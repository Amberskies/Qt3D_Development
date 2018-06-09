#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QEntity>
#include <QTransform>
#include <QMesh>
#include <QPhongMaterial>
#include <QPlaneMesh>

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
