#include "Graphics.h"

#include <QMesh>
#include <QPhongMaterial>

Graphics::Graphics()
{
	qWarning("Graphics Created");
}

Graphics::~Graphics()
{
	delete m_entity;
	//delete m_rootEntity; // gets deleted by parent=Window3D

	qWarning("Graphics Destroyed");
}

void Graphics::BeginFrame()
{
	// Empty
}

void Graphics::EndFrame()
{
	// Empty
}

void Graphics::test()
{
	Qt3DRender::QMesh *testMesh = new Qt3DRender::QMesh();
	testMesh->setSource(QUrl::fromLocalFile("Assets/Mesh/Dice.obj"));
	qWarning("test mesh loading");
	Qt3DExtras::QPhongMaterial *testMaterial = new Qt3DExtras::QPhongMaterial();
	testMaterial->setDiffuse(QColor(QRgb(0xD4AF37)));

	Qt3DCore::QTransform *testTransform = new Qt3DCore::QTransform();
	testTransform->setTranslation(QVector3D(15.0f, 1.0f, 15.0f));

	m_entity = new Qt3DCore::QEntity(m_rootEntity);
	m_entity->addComponent(testMesh);
	m_entity->addComponent(testMaterial);
	m_entity->addComponent(testTransform);
}

void Graphics::SetRoot(Qt3DCore::QEntity * rootEntity)
{
	m_rootEntity = rootEntity;
}
