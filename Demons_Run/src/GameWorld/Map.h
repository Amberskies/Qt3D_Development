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

public:
    explicit Map(Qt3DCore::QEntity *rootEntity);
    virtual ~Map();
    Qt3DCore::QEntity *createTile(float x, float y);

	// setters

	//getters
	const static int GetMapSizeX();
	const static int GetMapSizeY();

private:
	const static int m_mapSizeX = 30;
	const static int m_mapSizeY = 30;
	Qt3DCore::QEntity *m_rootEntity;
	Qt3DCore::QEntity *m_map[m_mapSizeX][m_mapSizeY];

};

#endif // MAP_H
