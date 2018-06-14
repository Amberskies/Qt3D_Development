#include "Physics.h"
#include "src/Core/Input.h"

Physics::Physics(Window3D & window3D, Graphics & gfx)
	: m_wnd(window3D)
	, m_graphics(gfx)
	, m_playerMoving(false)

{
	// Empty
}

Physics::~Physics()
{
	// Empty
}

void Physics::InitializePhysics()
{
	m_player1 = m_graphics.GetPlayer();
	m_enemy0 = m_graphics.GetEnemy0();
	m_enemy1 = m_graphics.GetEnemy1();
	m_enemy2 = m_graphics.GetEnemy2();
	m_score = 0;
	m_moveEnemy.setEnemy(m_enemy0, m_enemy1, m_enemy2);
}

void Physics::UpdatePhysics()
{
	QPoint mousePos = m_wnd.mapFromGlobal(Input::mousePosition());
	int centerPosx = m_wnd.width() / 2;
	int centerPosy = m_wnd.height() / 2;
	
	if (m_playerMoving) m_playerMoving =
		m_movePlayer.updatePlayerMovement(m_player1->getPlayer(), m_wnd.getCamera());

	if (Input::buttonPressed(Qt::RightButton) && !m_playerMoving)
		m_playerMoving = m_movePlayer.setMovePlayer(mousePos, QPoint(centerPosx, centerPosy));

	m_moveEnemy.UpdateMoveEnemy();

	QVector3D p1 = m_player1->getPlayerPosition();
	QVector3D e0 = m_enemy0->getEnemyPosition();
	QVector3D e1 = m_enemy1->getEnemyPosition();
	QVector3D e2 = m_enemy2->getEnemyPosition();
	
	bool collided = false;
	collided = CollisionTest(p1, e0);
	if (collided)
	{
		if (m_enemy0->getIsAlive())
		{
			m_score++;
			qWarning("Enemy 0 is dead");
		}

		m_enemy0->setDead(true);
	}
	
	collided = false;
	collided = CollisionTest(p1, e1);
	if (collided)
	{
		if (m_enemy1->getIsAlive()) 
		{
			m_score++;
			qWarning("Enemy 1 is dead");
		}

		m_enemy1->setDead(true);
	}
	
	collided = false;
	collided = CollisionTest(p1, e2);
	if (collided)
	{
		if (m_enemy2->getIsAlive())
		{
			m_score++;
			qWarning("Enemy 2 is dead");
		}

		m_enemy2->setDead(true);
	}

}

int Physics::GetScore()
{
	return m_score;
}

bool Physics::CollisionTest(QVector3D p1, QVector3D e1)
{
	bool collision = false;
	if ((p1.x() < e1.x() + 0.4f) &&
		(p1.x() > e1.x() - 0.4f) &&
		(p1.z() < e1.z() + 0.4f) &&
		(p1.z() > e1.z() - 0.4f))
	{
		collision = true;
	}
	return collision;
}

