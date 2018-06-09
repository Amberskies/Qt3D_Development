#pragma once

#include <QEntity>

#include "src/Rendering/Player.h"
#include "src/GameWorld/Map.h"

class Graphics
{
public:
	Graphics();
	~Graphics();

	void BeginFrame();
	void EndFrame();

	void createPlayer();
	void createMap();

	void UpdateGraphics();

	//void test();

	// Gets

	// Sets
	void SetRoot(Qt3DCore::QEntity *rootEntity);

private:
	Qt3DCore::QEntity *m_rootEntity = nullptr;
	Qt3DCore::QEntity *m_entity = nullptr;
	Player *m_player = nullptr;
	Map *m_map = nullptr;
};
