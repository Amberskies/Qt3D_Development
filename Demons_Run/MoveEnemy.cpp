#include "MoveEnemy.h"


MoveEnemy::MoveEnemy()
{
	//Empty
}

void MoveEnemy::setEnemy(Enemy *theEnemy0,
	Enemy *theEnemy1,
	Enemy *theEnemy2)
{
	m_thisEnemy0 = theEnemy0;
	m_thisEnemy1 = theEnemy1;
	m_thisEnemy2 = theEnemy2;
	m_direction0 = { 1.0f, 1.0f };
	m_direction1 = { -1.0f, 1.0f };
	m_direction2 = { 1.0f, -1.0f };

	m_speed = 0.04f;
}

void MoveEnemy::UpdateMoveEnemy()
{
	m_thisEnemy0->setEnemyPosition(move(m_thisEnemy0->getEnemyPosition(), m_direction0));
	m_thisEnemy1->setEnemyPosition(move(m_thisEnemy1->getEnemyPosition(), m_direction1));
	m_thisEnemy2->setEnemyPosition(move(m_thisEnemy2->getEnemyPosition(), m_direction2));
}

////////////////////Private///////////////////////////////////////////

QVector3D MoveEnemy::move(QVector3D position, QVector2D &direction)
{
	QVector3D finalPosition;
	if ((position.x() >= 28.0f) || (position.x() <= 0.0f)) direction.setX(-1.0f * direction.x());
	if ((position.z() >= 28.0f) || (position.z() <= 0.0f)) direction.setY(-1.0f * direction.y());

	finalPosition.setX(position.x() + (direction.x() * m_speed));
	finalPosition.setY(position.y());
	finalPosition.setZ(position.z() + (direction.y() * m_speed));

	return finalPosition;
}
