#pragma once

#include <QEntity>

#include "src/GameWorld/Player.h"
#include "src/GameWorld/Map.h"
#include "src/GameWorld/MapBoundaries.h"
#include "src/Rendering/Window3D.h"

class Graphics
{
public:
	Graphics();
	Graphics(const Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;
	~Graphics();

	void InitializeGraphics(Qt3DCore::QEntity *rootEntity);
	void UpdateGraphics();

	// Gets
	Player *GetPlayer();
	// Sets

private:
	Qt3DCore::QEntity *m_rootEntity = nullptr;
	Player *m_player = nullptr;
	Map *m_map = nullptr;
	MapBoundaries *m_mapSouth = nullptr;
	MapBoundaries *m_mapNorth = nullptr;
	MapBoundaries *m_mapEast = nullptr;
	MapBoundaries *m_mapWest = nullptr;
};
