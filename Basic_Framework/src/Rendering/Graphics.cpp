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

#include <QTexture>
#include <QTextureImage>
#include <QTextureMaterial>


void Graphics::test()
{
	m_entity = new Qt3DCore::QEntity(m_rootEntity);

	Qt3DRender::QMesh *testMesh = new Qt3DRender::QMesh();
	testMesh->setSource(QUrl::fromLocalFile("Assets/Mesh/Creeper.ply"));
	qWarning("test mesh loading");

	Qt3DRender::QTexture2D *texture = new Qt3DRender::QTexture2D();

	Qt3DRender::QTextureImage *tex = new Qt3DRender::QTextureImage();
	tex->setSource(QUrl::fromLocalFile("Assets/Mesh/creeper.png"));

	texture->addTextureImage(tex);
	
	Qt3DExtras::QTextureMaterial *testMaterial = new Qt3DExtras::QTextureMaterial();
	testMaterial->setTexture(texture);
	//Qt3DExtras::QPhongMaterial *testMaterial = new Qt3DExtras::QPhongMaterial();
	//testMaterial->setDiffuse(QColor(QRgb(0xD4AF37)));

	Qt3DCore::QTransform *testTransform = new Qt3DCore::QTransform();
	testTransform->setTranslation(QVector3D(0.0f, 0.0f, -5.0f));

	
	m_entity->addComponent(testMesh);
	m_entity->addComponent(testMaterial);
	m_entity->addComponent(testTransform);
}

void Graphics::SetRoot(Qt3DCore::QEntity * rootEntity)
{
	m_rootEntity = rootEntity;
}