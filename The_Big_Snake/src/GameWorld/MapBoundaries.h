#pragma once

#include <QObject>
#include <QEntity>
#include <QMesh>
#include <QPhongMaterial>


class MapBoundaries : public QObject
{
	Q_OBJECT

public:

	explicit MapBoundaries(Qt3DCore::QEntity *rootEntity);
	virtual ~MapBoundaries();

	void CreateSouthBoundary();
	void CreateNorthBoundary();
	void CreateWestBoundary();
	void CreateEastBoundary();

private:
	Qt3DCore::QEntity *m_rootEntity;
	Qt3DRender::QMesh *m_mesh = nullptr;
	Qt3DExtras::QPhongMaterial *m_material = nullptr;
};
