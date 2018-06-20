#include "Map.h"
#include "src/Core/ModelLoader.h"
#include <QPhongMaterial>

Map::Map(Qt3DCore::QEntity *rootEntity) :
	m_rootEntity(rootEntity)
{
	Qt3DRender::QMesh *planeMesh = ModelLoader::LoadMesh("../Assets/Maps/BigBaseTile30x30.obj");
	Qt3DExtras::QPhongMaterial *planeMaterial = ModelLoader::Material(QColor(Qt::darkGreen));

	m_map = new Qt3DCore::QEntity(m_rootEntity);

	Qt3DCore::QTransform *planeTransform = new Qt3DCore::QTransform();
	planeTransform->setTranslation(QVector3D(0.0f, 0.0f, 30.0f));
	m_map->addComponent(planeMesh);
	m_map->addComponent(planeMaterial);
	m_map->addComponent(planeTransform);
}

Map::~Map()
{
	delete m_map;
}

const int Map::GetMapSizeX()
{
	return m_mapSizeX;
}

const int Map::GetMapSizeY()
{
	return m_mapSizeY;
}
