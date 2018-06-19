#include "Graphics.h"

#include "src/Core/Input.h"
#include <QString>
#include <QObjectPicker>


Graphics::Graphics(Window3D & window3D)
	: m_wnd(window3D)
	, m_counter(0)
	, m_hasNotCollided(true)
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
	delete m_entity;
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
	if (m_hasNotCollided)
	{
		m_moveSnake.UpdateMoveSnake(m_player, m_wnd.GetCamera());

		m_counter++;
		if (m_counter >= 100)
		{
			QString f = QString::number((int)m_wnd.GetFps());
			m_wnd.setTitle("Your FPS =  " + f + "    ");
			m_counter = 0;
		}

		if (Input::buttonPressed(Qt::LeftButton))
		{
			m_wnd.SetLightPosition(QVector3D(5.0f, 29.0f, 5.01f));
		}
		PickingTest();
	}
	m_hasNotCollided = m_moveSnake.checkCollision();
}

void Graphics::PickingTest()
{
	if (m_player->GetPlayerSelector()->containsMouse())
	{
		m_player->SetPlayerColor(QColor(Qt::lightGray));
	}
	else
	{
		m_player->SetPlayerColor(QColor(QRgb(0xDD10EE)));
	}
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
