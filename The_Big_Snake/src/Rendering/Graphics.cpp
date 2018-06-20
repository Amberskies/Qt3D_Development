#include "Graphics.h"




Graphics::Graphics()

{
	// Empty
}

Graphics::~Graphics()
{
	delete m_mapWest;
	delete m_mapEast;
	delete m_mapSouth;
	delete m_mapNorth;
	delete m_map;
	delete m_player;
	//delete m_fpsEntity; // gets deleted by parent=Window3D
	//delete m_rootEntity; // gets deleted by parent=Window3D
}

void Graphics::InitializeGraphics(Qt3DCore::QEntity * rootEntity)
{
	m_rootEntity = rootEntity;
	m_player = new Player(m_rootEntity);
	m_map = new Map(m_rootEntity);
	m_mapSouth = new MapBoundaries(m_rootEntity);
	m_mapSouth->CreateSouthBoundary();
	m_mapNorth = new MapBoundaries(m_rootEntity);
	m_mapNorth->CreateNorthBoundary();
	m_mapWest = new MapBoundaries(m_rootEntity);
	m_mapWest->CreateWestBoundary();
	m_mapEast = new MapBoundaries(m_rootEntity);
	m_mapEast->CreateEastBoundary();
}

void Graphics::UpdateGraphics()
{
	//Empty
}

Player * Graphics::GetPlayer()
{
	return m_player;
}
// Notes for textures

///////////////////////////////////////////////////////////////
//#include <QMesh>
//#include <QTexture>
//#include <QTextureImage>
//#include <QTextureMaterial>
////#include <QPhongMaterial>
//
//void Graphics::test()
//{
//	Qt3DRender::QMesh *testMesh = new Qt3DRender::QMesh();
//	testMesh->setSource(QUrl::fromLocalFile("Assets/Mesh/Creeper.ply"));
//	qWarning("test mesh loading");
//
//	Qt3DRender::QTexture2D *texture = new Qt3DRender::QTexture2D();
//	Qt3DRender::QTextureImage *tex = new Qt3DRender::QTextureImage();
//	tex->setSource(QUrl::fromLocalFile("Assets/Mesh/creeper.png"));
//	texture->addTextureImage(tex);
//	Qt3DExtras::QTextureMaterial *testMaterial = new Qt3DExtras::QTextureMaterial();
//	testMaterial->setTexture(texture);
//
//
//	//Qt3DExtras::QPhongMaterial *testMaterial = new Qt3DExtras::QPhongMaterial();
//	//testMaterial->setDiffuse(QColor(QRgb(0xD4AF37)));
//
//	Qt3DCore::QTransform *testTransform = new Qt3DCore::QTransform();
//	testTransform->setTranslation(QVector3D(0.0f, 0.0f, 5.0f));
//
//	m_entity = new Qt3DCore::QEntity(m_rootEntity);
//	m_entity->addComponent(testMesh);
//	m_entity->addComponent(testMaterial);
//	m_entity->addComponent(testTransform);
//}
