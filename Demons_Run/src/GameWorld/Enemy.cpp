#include "Enemy.h"

#include <QTransform>
#include <QMesh>
#include <QPhongMaterial> 
#include "src/Core/ModelLoader.h"

Enemy::Enemy(Qt3DCore::QEntity *rootEntity) :
    m_rootEntity(rootEntity)
{
    Qt3DRender::QMesh *testMesh = ModelLoader::LoadMesh("../Assets/Player/Player1.ply");
	Qt3DExtras::QPhongMaterial *testMaterial = ModelLoader::Material(QColor(QRgb(0xF40000)));

    Qt3DCore::QTransform *testTransform = new Qt3DCore::QTransform();
    testTransform->setTranslation(QVector3D(0.0f, 1.0f, 0.0f));

    m_Enemy = new Qt3DCore::QEntity(m_rootEntity);
    m_Enemy->addComponent(testMesh);
    m_Enemy->addComponent(testMaterial);
    m_Enemy->addComponent(testTransform);

	qWarning("Enemy Created");
}

Enemy::~Enemy()
{
    qWarning("Enemy Shutdown");
}

Qt3DCore::QEntity *Enemy::getEnemy()
{
    return m_Enemy;
}

QVector3D Enemy::getEnemyPosition()
{
	Qt3DCore::QComponentVector EnemyVector;
	Qt3DCore::QTransform *EnemyTransform;
	
	EnemyVector = m_Enemy->components();
	EnemyTransform = qobject_cast<Qt3DCore::QTransform *>(EnemyVector.at(2));
	return EnemyTransform->translation();
}

void Enemy::setEnemyPosition(QVector3D EnemyPosition)
{
	Qt3DCore::QComponentVector EnemyVector;
	Qt3DCore::QTransform *EnemyTransform;

	EnemyVector = m_Enemy->components();
	EnemyTransform = qobject_cast<Qt3DCore::QTransform *>(EnemyVector.at(2));
	EnemyTransform->setTranslation(EnemyPosition);
}

