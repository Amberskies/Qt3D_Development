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

	void startScreen();
	void createPlayer();
	void createEnemy();
	void createMap();

	void UpdateGraphics();

	//void test();

	// Gets
	Player* GetPlayer();
	Enemy* GetEnemy0();
	Enemy* GetEnemy1();
	Enemy* GetEnemy2();
	// Sets
	void SetRoot(Qt3DCore::QEntity *rootEntity);
	void SetStartScreen(bool isShowing);

private:
	Qt3DCore::QEntity *m_rootEntity = nullptr;
	Map *m_map = nullptr;
	Player *m_player = nullptr;
	Enemy *m_enemy0 = nullptr;
	Enemy *m_enemy1 = nullptr;
	Enemy *m_enemy2 = nullptr;
	Qt3DCore::QEntity *m_startScreen = nullptr;
};
