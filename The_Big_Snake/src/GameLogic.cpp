#include "GameLogic.h"

#include <QString>
#include <QObjectPicker>

#include "src/GameRules/Dice.h"


GameLogic::GameLogic(Graphics *gfx, Window3D& window3D)
	: m_wnd(window3D)
	, m_gfx(gfx)
{
	Dice::InitializeDice();
}

GameLogic::~GameLogic()
{
	// Empty deletes done by thier parents
}


void GameLogic::InititializeGameLogic()
{
	m_player = m_gfx->GetPlayer();
	m_goal = m_gfx->GetGoals();
}

bool GameLogic::UpdateGameLogic()
{
	if (!m_collided)
	{
		m_moveSnake.UpdateMoveSnake(m_player, m_wnd.GetCamera());

		m_counter++;
		if (m_counter >= 100)
		{
			QString f = QString::number((int)m_wnd.GetFps());
			m_wnd.setTitle("Your FPS =  " + f + "    ");
			m_counter = 0;
		}

		//PickingTest(); // highlights snakes head if mouse hovers over
	}
	m_collided = m_moveSnake.checkCollision(m_player->GetPlayerPosition());
	m_goalReached = checkGoalReached();
	if (m_goalReached)
	{
		m_moveSnake.GrowSnake();
		m_score++;

		for (int i = 0; i < m_numGoals; i++)
		{
			QVector3D position =  RespawnGoal();
			m_goal->SetGoalPosition(i, position);
		}
	}

	return m_collided;
}

bool GameLogic::checkGoalReached()
{
	bool reached = false;
	// Collision with Goal
	QVector3D head = m_player->GetPlayerPosition();
	int i = m_numGoals;
	while (i > 0)
	{
		QVector3D goal = m_goal->GetGoalPosition(i - 1);
		if ( ((int)head.x() == (int)goal.x()) &&
			 ((int)head.z() == (int)goal.z()) ) reached = true;
		i--;
	}
	return reached;
}

QVector3D GameLogic::RespawnGoal()
{
	QVector3D newPos = { 0.0f, 0.5f, 0.0f };

	bool isTileFull = true;
	while (isTileFull)
	{
		newPos.setX(Dice::RollDice(1, 29));
		newPos.setZ(Dice::RollDice(1, 29));
		isTileFull = m_moveSnake.checkCollision(newPos);
	}

	return newPos;
}

//
//void GameLogic::PickingTest()
//{
//	if (m_player->GetPlayerSelector()->containsMouse())
//	{
//		m_player->SetPlayerColor(QColor(Qt::lightGray));
//	}
//	else
//	{
//		m_player->SetPlayerColor(QColor(QRgb(0xDD10EE)));
//	}
//}