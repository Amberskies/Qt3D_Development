#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QEntity>


class Enemy : public QObject
{
    Q_OBJECT

    Qt3DCore::QEntity *m_rootEntity;
    Qt3DCore::QEntity *m_Enemy;
public:
	
    Enemy(Qt3DCore::QEntity *rootEntity);
    ~Enemy();

	// getters
    Qt3DCore::QEntity *getEnemy();
	bool getIsAlive();
	QVector3D getEnemyPosition();

	//setters
	void setEnemyPosition(QVector3D playerPosition);
	void setDead(bool isdead);

private:
	bool isAlive = true;
};

#endif // ENEMY_H
