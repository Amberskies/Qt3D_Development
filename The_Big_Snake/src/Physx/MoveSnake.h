#pragma once

#include <QVector3D>
#include <QCamera>

#include "src/GameWorld/Player.h"


class MoveSnake
{
public:
	MoveSnake();
	~MoveSnake();

	void UpdateMoveSnake(Player *snake, Qt3DRender::QCamera *camera);
	bool checkCollision();

private:
	void FinalMovement();

	QVector3D m_moveDirection = { 0.0f, 0.0f, 1.0f };
	QVector3D m_currentPosition = { 0.0f, 0.0f, 0.0f };
	float m_moveSpeed = 0.04f;
	Player *m_snake = nullptr;
	Qt3DRender::QCamera *m_camera = nullptr;
};

