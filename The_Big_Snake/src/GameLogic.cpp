#include "GameLogic.h"

#include <QString>
#include <QObjectPicker>
#include "src/Core/Input.h"

GameLogic::GameLogic(Graphics *gfx, Window3D& window3D)
	: m_wnd(window3D)
	, m_gfx(gfx)
{
	// Empty
}

GameLogic::~GameLogic()
{
	// Empty deletes done by thier parents
}


void GameLogic::InititializeGameLogic()
{
	m_player = m_gfx->GetPlayer();

}

void GameLogic::UpdateGameLogic()
{
	if (m_hasNotCollided)
	{
		m_moveSnake.UpdateMoveSnake(m_player, m_wnd.GetCamera());

		m_counter++;
		if (m_counter >= 100)
		{
			QString f = QString::number((int)m_wnd.GetFps());
			m_wnd.setTitle("Your FPS =  " + f + "    ");
			m_counter = 0;
		}

		if (Input::buttonPressed(Qt::LeftButton))
		{
			m_wnd.SetLightPosition(QVector3D(5.0f, 29.0f, 5.01f));
		}
		PickingTest();
	}
	m_hasNotCollided = m_moveSnake.checkCollision();
}

void GameLogic::PickingTest()
{
	if (m_player->GetPlayerSelector()->containsMouse())
	{
		m_player->SetPlayerColor(QColor(Qt::lightGray));
	}
	else
	{
		m_player->SetPlayerColor(QColor(QRgb(0xDD10EE)));
	}
}