#pragma once

#include "src/Physx/MoveSnake.h"
#include "src/GameWorld/Player.h"
#include "src/Rendering/Graphics.h"
#include "src/Rendering/Window3D.h"

class GameLogic
{
public:
	GameLogic(Graphics *gfx, class Window3D& window3D);
	~GameLogic();

	void InititializeGameLogic();
	void UpdateGameLogic();

	int StartScreen();
	int GameOver();


private:
	void PickingTest();

	int m_counter = 0;
	bool m_hasNotCollided = true;
	MoveSnake m_moveSnake;
	Player *m_player = nullptr;
	Graphics *m_gfx = nullptr;;
	Window3D& m_wnd;
};