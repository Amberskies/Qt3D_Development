#include "MapBoundaries.h"
#include "src/Core/ModelLoader.h"

#include <QTransform>

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
	int x = 0;
	int z = 30;
	for (; x <= 30; x++)
	{
		Qt3DCore::QEntity *tile = new Qt3DCore::QEntity(m_rootEntity);
		Qt3DCore::QTransform *tileTransform = new Qt3DCore::QTransform();
		tileTransform->setTranslation(QVector3D(x, 0.0f, z));
		tileTransform->setRotationX(90.0f);
		tile->addComponent(m_mesh);
		tile->addComponent(m_material);
		tile->addComponent(tileTransform);
	}
}

void MapBoundaries::CreateNorthBoundary()
{
	int x = 0;
	int z = 0;
	for (; x <= 30; x++)
	{
		Qt3DCore::QEntity *tile = new Qt3DCore::QEntity(m_rootEntity);
		Qt3DCore::QTransform *tileTransform = new Qt3DCore::QTransform();
		tileTransform->setTranslation(QVector3D(x, 0.0f, z + 0.5f));
		tileTransform->setRotationX(90.0f);
		tile->addComponent(m_mesh);
		tile->addComponent(m_material);
		tile->addComponent(tileTransform);
	}
}

void MapBoundaries::CreateWestBoundary()
{
	int x = 0;
	int z = 0;
	for (; z <= 30; z++)
	{
		Qt3DCore::QEntity *tile = new Qt3DCore::QEntity(m_rootEntity);
		Qt3DCore::QTransform *tileTransform = new Qt3DCore::QTransform();
		tileTransform->setTranslation(QVector3D(x, 0.0f, z));
		tileTransform->setRotationZ(90.0f);
		tile->addComponent(m_mesh);
		tile->addComponent(m_material);
		tile->addComponent(tileTransform);
	}
}

void MapBoundaries::CreateEastBoundary()
{
	int x = 30;
	int z = 0;
	for (; z <= 30; z++)
	{
		Qt3DCore::QEntity *tile = new Qt3DCore::QEntity(m_rootEntity);
		Qt3DCore::QTransform *tileTransform = new Qt3DCore::QTransform();
		tileTransform->setTranslation(QVector3D(x - 0.5f, 0.0f, z));
		tileTransform->setRotationZ(90.0f);
		tile->addComponent(m_mesh);
		tile->addComponent(m_material);
		tile->addComponent(tileTransform);
	}
}
