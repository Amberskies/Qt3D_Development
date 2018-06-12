#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QEntity>


class Enemy : public QObject
{
    Q_OBJECT

    Qt3DCore::QEntity *m_rootEntity;
    Qt3DCore::QEntity *m_Enemy;
public:
    explicit Enemy(Qt3DCore::QEntity *rootEntity);
    virtual ~Enemy();

	// getters
    Qt3DCore::QEntity *getEnemy();
	QVector3D getEnemyPosition();

	//setters
	void setEnemyPosition(QVector3D playerPosition);
};

#endif // PLAYER_H
