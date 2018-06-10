#pragma once

#include <QMesh>
#include <QPhongMaterial>

class ModelLoader
{
public:
	static Qt3DRender::QMesh* LoadMesh(QString file);
	static Qt3DExtras::QPhongMaterial* Material(QColor diffuse);
};

