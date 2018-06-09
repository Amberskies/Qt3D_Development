#include "Player.h"

#include <QTransform>
#include <QMesh>
#include <QPhongMaterial>

Player::Player(Qt3DCore::QEntity *rootEntity) :
    m_rootEntity(rootEntity)
{
    Qt3DRender::QMesh *testMesh = new Qt3DRender::QMesh();
    testMesh->setSource(QUrl::fromLocalFile("Assets/Player/Player1.ply"));

    Qt3DExtras::QPhongMaterial *testMaterial = new Qt3DExtras::QPhongMaterial();
    testMaterial->setDiffuse(QColor(QRgb(0xD4AF37)));

    Qt3DCore::QTransform *testTransform = new Qt3DCore::QTransform();
    testTransform->setTranslation(QVector3D(15.0f, 0.5f, 15.0f));

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

