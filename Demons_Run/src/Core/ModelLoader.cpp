#include "ModelLoader.h"

Qt3DRender::QMesh * ModelLoader::LoadMesh(QString file)
{
	Qt3DRender::QMesh *newMesh = new Qt3DRender::QMesh();
	newMesh->setSource(QUrl::fromLocalFile(file));
	return newMesh;
}

Qt3DExtras::QPhongMaterial * ModelLoader::Material(QColor diffuse)
{
	Qt3DExtras::QPhongMaterial *newMaterial = new Qt3DExtras::QPhongMaterial();
	newMaterial->setDiffuse(diffuse);
	return newMaterial;
}
