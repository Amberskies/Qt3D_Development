#pragma once

#include <QEntity>

#include "src/GameWorld/Player.h"
#include "src/GameWorld/Enemy.h"
#include "src/GameWorld/Map.h"



class Graphics
{
public:
	Graphics();
	~Graphics();

	void BeginFrame();
	void EndFrame();

	void createPlayer();
	void createEnemy();
	void createMap();

	void UpdateGraphics();

	//void test();

	// Gets
	Player* GetPlayer();
	Enemy* GetEnemy();
	// Sets
	void SetRoot(Qt3DCore::QEntity *rootEntity);

private:
	Qt3DCore::QEntity *m_rootEntity = nullptr;
	Map *m_map = nullptr;
	Player *m_player = nullptr;
	Enemy *m_enemy = nullptr;
};
