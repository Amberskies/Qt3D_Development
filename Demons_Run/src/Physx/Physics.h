#pragma once

#include "MovePlayer.h"
#include "src/Rendering/Window3D.h"
#include "src/GameWorld/Player.h"

class Physics
{
public:
	Physics(class Window3D& window3D);
	Physics(const Physics&) = delete;
	Physics& operator=(const Physics&) = delete;
	~Physics();

	void UpdatePhysics();

	// getters

	// setters
	void setPlayer(Player *player);

private:
	Window3D & m_wnd;
	MovePlayer m_movePlayer;
	bool m_playerMoving;
	Player *m_player = nullptr;

};
