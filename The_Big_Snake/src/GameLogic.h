#pragma once

#include "src/Physx/MoveSnake.h"
#include "src/GameWorld/Player.h"
#include "src/GameWorld/Goal.h"
#include "src/Rendering/Graphics.h"
#include "src/Rendering/Window3D.h"

class GameLogic
{
public:
	GameLogic(Graphics *gfx, class Window3D& window3D);
	~GameLogic();

	void InititializeGameLogic();
	bool UpdateGameLogic();

private:
	bool checkGoalReached();
	QVector3D RespawnGoal();
	//void PickingTest();

	int m_counter = 0;
	bool m_collided = false;
	bool m_goalReached = false;
	int m_numGoals = 1;
	int m_score = 0;
	MoveSnake m_moveSnake;
	Player *m_player = nullptr;
	Goal *m_goal = nullptr;
	Graphics *m_gfx = nullptr;
	Window3D& m_wnd;
};