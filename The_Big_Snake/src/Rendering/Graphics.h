#pragma once

#include <QEntity>

#include "src/GameWorld/Player.h"
#include "src/GameWorld/Map.h"
#include "src/GameWorld/MapBoundaries.h"
#include "src/Rendering/Window3D.h"
#include "src/Physx/MoveSnake.h"

class Graphics
{
public:
	Graphics(class Window3D& window3D);
	Graphics(const Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;
	~Graphics();

	void InitializeGraphics(Qt3DCore::QEntity *rootEntity);
	void UpdateGraphics();
	void PickingTest();

	// Gets

	// Sets

private:
	Qt3DCore::QEntity *m_rootEntity = nullptr;
	Qt3DCore::QEntity *m_entity = nullptr;
	Qt3DCore::QEntity *m_fpsEntity = nullptr;
	Player *m_player = nullptr;
	Map *m_map = nullptr;
	MapBoundaries *m_mapSouth = nullptr;
	MapBoundaries *m_mapNorth = nullptr;
	MapBoundaries *m_mapEast = nullptr;
	MapBoundaries *m_mapWest = nullptr;
	Window3D& m_wnd;
	MoveSnake m_moveSnake;
	int m_counter = 0;
	bool m_hasNotCollided = true;
};
