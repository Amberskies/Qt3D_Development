#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>

#include <Qt3DRender/qmesh.h>

#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/qplanemesh.h>

class Map : public QObject
{
    Q_OBJECT
    Qt3DCore::QEntity *m_rootEntity;
    Qt3DCore::QEntity *m_map[30][30];
public:
    explicit Map(Qt3DCore::QEntity *rootEntity);
    virtual ~Map();
    Qt3DCore::QEntity *createTile(float x, float y);

signals:

public slots:
};

#endif // MAP_H
