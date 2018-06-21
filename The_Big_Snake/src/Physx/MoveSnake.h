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
	bool checkCollision(QVector3D pos);
	void GrowSnake();

private:
	void FinalMovement();

	static const int m_maxSegments = 100;
	QVector3D m_segments[m_maxSegments];
	int m_currentSegments = 0;

	QVector3D m_moveDirection = { 0.0f, 0.0f, 1.0f };

	Player *m_snake = nullptr;
	Qt3DRender::QCamera *m_camera = nullptr;
	bool m_inhibitRight = false;
	bool m_inhibitLeft = false;
	float m_countdown = 15.0f;
	float m_moveSpeed = 15.0f;
	float m_currentRotation = 0.0f;
};

