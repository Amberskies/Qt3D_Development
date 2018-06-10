#include "Player.h"

#include <QTransform>
#include <QMesh>
#include <QPhongMaterial> // texture example is in Graphics.cpp
#include "src/Core/ModelLoader.h"

Player::Player(Qt3DCore::QEntity *rootEntity) :
    m_rootEntity(rootEntity)
{
    Qt3DRender::QMesh *testMesh = ModelLoader::LoadMesh("../Assets/Player/Player1.ply");
	Qt3DExtras::QPhongMaterial *testMaterial = ModelLoader::Material(QColor(QRgb(0xD4AF37)));

    Qt3DCore::QTransform *testTransform = new Qt3DCore::QTransform();
    testTransform->setTranslation(QVector3D(15.0f, 1.0f, 15.0f));

    m_player = new Qt3DCore::QEntity(m_rootEntity);
    m_player->addComponent(testMesh);
    m_player->addComponent(testMaterial);
    m_player->addComponent(testTransform);

	qWarning("Player Created");
}

Player::~Player()
{
    qWarning("Player Shutdown");
}

Qt3DCore::QEntity *Player::getPlayer()
{
    return m_player;
}

QVector3D Player::getPlayerPosition()
{
	Qt3DCore::QComponentVector playerVector;
	Qt3DCore::QTransform *playerTransform;
	
	playerVector = m_player->components();
	playerTransform = qobject_cast<Qt3DCore::QTransform *>(playerVector.at(2));
	return playerTransform->translation();
}

void Player::setPlayerPosition(QVector3D playerPosition)
{
	Qt3DCore::QComponentVector playerVector;
	Qt3DCore::QTransform *playerTransform;

	playerVector = m_player->components();
	playerTransform = qobject_cast<Qt3DCore::QTransform *>(playerVector.at(2));
	playerTransform->setTranslation(playerPosition);
}

