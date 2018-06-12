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
	m_enemy1 = m_graphics.GetEnemy();
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

	QVector3D p1 = m_player1->getPlayerPosition();
	QVector3D e1 = m_enemy1->getEnemyPosition();

	if ( (p1.x() < e1.x() + 0.4f) &&
		 (p1.x() > e1.x() - 0.4f) &&
		 (p1.z() < e1.z() + 0.4f) &&
		 (p1.z() > e1.z() - 0.4f) )
	{
		m_enemy1->setDead(true);
	}
}

