#include "Player.h"
#include "src/Core/ModelLoader.h"

Player::Player(Qt3DCore::QEntity *rootEntity) :
	m_rootEntity(rootEntity)
{
	m_mesh = ModelLoader::LoadMesh("../Assets/Mesh/Dice.ply");
	m_material = ModelLoader::Material(QColor(QRgb(0xDD10EE)));

	m_transform = new Qt3DCore::QTransform();
	m_transform->setTranslation(QVector3D(10.0f, 1.0f, 10.0f));

	m_picker = new Qt3DRender::QObjectPicker();
	m_picker->setHoverEnabled(true);
	m_picker->setEnabled(true);
	
	m_player = new Qt3DCore::QEntity(m_rootEntity);
	m_player->addComponent(m_mesh);
	m_player->addComponent(m_material);
	m_player->addComponent(m_transform);
	m_player->addComponent(m_picker);
}


Player::~Player()
{
	delete m_picker;
	delete m_transform;
	delete m_material;
	delete m_mesh;
}

Qt3DCore::QEntity *Player::GetPlayer()
{
	return m_player;
}

QVector3D Player::GetPlayerPosition()
{
	return m_transform->translation();
}

Qt3DRender::QObjectPicker * Player::GetPlayerSelector()
{
	return m_picker;
}

void Player::SetPlayerRotaion(QVector3D axis, float angle)
{
	m_transform->setRotation(QQuaternion::fromAxisAndAngle(axis, angle));

}

void Player::SetPlayerPosition(QVector3D playerPosition)
{
	m_transform->setTranslation(playerPosition);
}

void Player::SetPlayerColor(QColor playerColor)
{
	m_material->setDiffuse(playerColor);
}

