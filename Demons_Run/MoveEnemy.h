#pragma once

#include <QVector2D>
#include <QVector3D>
#include "src/GameWorld/Enemy.h"

class MoveEnemy
{
public:
	MoveEnemy();


	void setEnemy(Enemy *theEnemy0,
		Enemy *theEnemy1,
		Enemy *theEnemy2);

	void UpdateMoveEnemy();

private:

	QVector3D move(QVector3D position, QVector2D &direction);
	float m_speed = 0.0f;
	Enemy *m_thisEnemy0 = nullptr;
	Enemy *m_thisEnemy1 = nullptr;
	Enemy *m_thisEnemy2 = nullptr;
	QVector2D m_direction0;
	QVector2D m_direction1;
	QVector2D m_direction2;

};