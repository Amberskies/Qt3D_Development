#include "Player.h"
#include "src/Core/ModelLoader.h"

Player::Player(Qt3DCore::QEntity *rootEntity) :
	m_rootEntity(rootEntity)
{
	m_mesh = ModelLoader::LoadMesh("../Assets/Mesh/Dice.ply");
	m_material = ModelLoader::Material(QColor(QRgb(0xDD10EE)));

	m_segTransform[0] = new Qt3DCore::QTransform();
	m_segTransform[0]->setTranslation(QVector3D(10.0f, 1.0f, 10.0f));

	m_picker = new Qt3DRender::QObjectPicker();
	m_picker->setHoverEnabled(true);
	m_picker->setEnabled(true);
	
	m_player = new Qt3DCore::QEntity(m_rootEntity);
	m_player->addComponent(m_mesh);
	m_player->addComponent(m_material);
	m_player->addComponent(m_segTransform[0]);
	m_player->addComponent(m_picker);

	m_segMesh = ModelLoader::LoadMesh("../Assets/Player/Player1.ply");
	m_segMaterial = ModelLoader::Material(m_color);

}


Player::~Player()
{
	delete m_picker;
    // delete[] &m_segTransform; lol MS dont like this - so memory leak AWAY !
	delete m_material;
	delete m_mesh;
}

void Player::Grow(int segment, QVector3D location)
 {
	m_segTransform[segment] = new Qt3DCore::QTransform();
	m_segTransform[segment]->setTranslation(location);

	m_segment[segment] = new Qt3DCore::QEntity(m_rootEntity);
	m_segment[segment]->addComponent(m_segMesh);
	m_segment[segment]->addComponent(m_segMaterial);
	m_segment[segment]->addComponent(m_segTransform[segment]);
}

Qt3DCore::QEntity *Player::GetPlayer()
{
	return m_player;
}

QVector3D Player::GetPlayerPosition()
{
	return m_segTransform[0]->translation();
}

float Player::GetPlayerRotation()
{
	return m_segTransform[0]->rotationY();
}

Qt3DRender::QObjectPicker * Player::GetPlayerSelector()
{
	return m_picker;
}


void Player::SetPlayerRotaion(QVector3D axis, float angle)
{
	m_segTransform[0]->setRotation(QQuaternion::fromAxisAndAngle(axis, angle));

}

void Player::SetPlayerPosition(QVector3D playerPosition)
{
	m_segTransform[0]->setTranslation(playerPosition);
}

void Player::SetPlayerColor(QColor playerColor)
{
	m_material->setDiffuse(playerColor);
}

void Player::SetSegmentPosition(int segment, QVector3D segmentPosition)
{
	m_segTransform[segment]->setTranslation(segmentPosition);
}
