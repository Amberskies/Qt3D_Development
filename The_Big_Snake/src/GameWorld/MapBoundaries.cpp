#include "MapBoundaries.h"
#include "src/Core/ModelLoader.h"


MapBoundaries::MapBoundaries(Qt3DCore::QEntity *rootEntity) :
	m_rootEntity(rootEntity)
{
	m_mesh = ModelLoader::LoadMesh("../Assets/Maps/BaseTile.obj");
	m_material = ModelLoader::Material(QColor(Qt::darkBlue));
}

MapBoundaries::~MapBoundaries()
{
	delete m_material;
	delete m_mesh;
}

void MapBoundaries::CreateSouthBoundary()
{
	// Empty
}

void MapBoundaries::CreateNorthBoundary()
{
	// Empty
}

void MapBoundaries::CreateWestBoundary()
{
	// Empty
}

void MapBoundaries::CreateEastBoundary()
{
	// Empty
}
