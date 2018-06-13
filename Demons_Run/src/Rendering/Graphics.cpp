#include "Graphics.h"


Graphics::Graphics()
{
	qWarning("Graphics Created");

}

Graphics::~Graphics()
{
	delete m_map;
	delete m_enemy0;
	delete m_enemy1;
	delete m_enemy2;
	delete m_player;

	//delete m_rootEntity; // gets deleted by parent=Window3D

	qWarning("Graphics Destroyed");
}

void Graphics::BeginFrame()
{
	// Empty
}

void Graphics::EndFrame()
{
	// Empty
}



void Graphics::createPlayer()
{
	m_player = new Player(m_rootEntity);
}

void Graphics::createEnemy()
{
	m_enemy0 = new Enemy(m_rootEntity);
	m_enemy1 = new Enemy(m_rootEntity);
	m_enemy2 = new Enemy(m_rootEntity);
}

void Graphics::createMap()
{
	m_map = new Map(m_rootEntity);
}

void Graphics::UpdateGraphics()
{
}


Player * Graphics::GetPlayer()
{
	return m_player;
}

Enemy * Graphics::GetEnemy0()
{
	return m_enemy0;
}

Enemy * Graphics::GetEnemy1()
{
	return m_enemy1;
}

Enemy * Graphics::GetEnemy2()
{
	return m_enemy2;
}

void Graphics::SetRoot(Qt3DCore::QEntity * rootEntity)
{
	m_rootEntity = rootEntity;
}
