#pragma once

#include "MovePlayer.h"
#include "src/Rendering/Window3D.h"
#include "src/GameWorld/Player.h"
#include "src/GameWorld/Enemy.h"
#include "src/Rendering/Graphics.h"

class Physics
{
public:
	Physics(class Window3D& window3D, class Graphics& gfx);
	Physics(const Physics&) = delete;
	Physics& operator=(const Physics&) = delete;
	~Physics();

	void InitializePhysics();
	void UpdatePhysics();

	// getters

	// setters

private:
	Window3D & m_wnd;
	Graphics & m_graphics;

	MovePlayer m_movePlayer;
	bool m_playerMoving;

	Player *m_player1 = nullptr;
	Enemy *m_enemy1 = nullptr;
};
