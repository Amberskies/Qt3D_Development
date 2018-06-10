#include "Physics.h"
#include "src/Core/Input.h"

Physics::Physics(Window3D & window3D)
	: m_wnd(window3D)
	, m_playerMoving(false)

{
	// Empty
}

Physics::~Physics()
{
	// Empty
}

void Physics::UpdatePhysics()
{
	QPoint mousePos = m_wnd.mapFromGlobal(Input::mousePosition());
	int centerPosx = m_wnd.width() / 2;
	int centerPosy = m_wnd.height() / 2;
	
	if (m_playerMoving) m_playerMoving =
		m_movePlayer.updatePlayerMovement(m_player->getPlayer(), m_wnd.getCamera());

	if (Input::buttonPressed(Qt::RightButton) && !m_playerMoving)
		m_playerMoving = m_movePlayer.setMovePlayer(mousePos, QPoint(centerPosx, centerPosy));
	
}

void Physics::setPlayer(Player * player)
{
	m_player = player;
}
