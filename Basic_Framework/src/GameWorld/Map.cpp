#include "Map.h"

Map::Map(Qt3DCore::QEntity *rootEntity) :
    m_rootEntity(rootEntity)
{
    for(float x = 0.0f; x < 30.0f; x++)
    {
        for(float y = 0.0f; y < 30.0f; y++)
            m_map[int(x)][(int)y] = createTile(x - 0.5f, y - 0.5f);
    }
	qWarning("Map Created");
}

Map::~Map()
{
    qWarning("Map Shutdown");
}

Qt3DCore::QEntity *Map::createTile(float x, float y)
{
    Qt3DExtras::QPlaneMesh *planeMesh = new Qt3DExtras::QPlaneMesh();
    planeMesh->setWidth(0.9f);
    planeMesh->setHeight(0.9f);

    Qt3DExtras::QPhongMaterial *planeMaterial = new Qt3DExtras::QPhongMaterial();
    planeMaterial->setDiffuse(QColor(QRgb(0x105510)));

    Qt3DCore::QTransform *planeTransform = new Qt3DCore::QTransform();
    //planeTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 45.0f));
    planeTransform->setTranslation(QVector3D(x, 0.0f, y));


    // Plane
    Qt3DCore::QEntity *tile = new Qt3DCore::QEntity(m_rootEntity);
    tile->addComponent(planeMesh);
    tile->addComponent(planeMaterial);
    tile->addComponent(planeTransform);

    return tile;
}


