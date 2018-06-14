#include "Graphics.h"

#include "src/Core/ModelLoader.h"

Graphics::Graphics()
{
	qWarning("Graphics Created");

}

Graphics::~Graphics()
{
	delete m_map;
	delete m_enemy0;
	delete m_enemy1;
	delete m_enemy2;
	delete m_startScreen;
	delete m_player;

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



void Graphics::startScreen()
{
	Qt3DRender::QMesh *testMesh = ModelLoader::LoadMesh("../Assets/Mesh/StartText.obj");
	Qt3DExtras::QPhongMaterial *testMaterial = ModelLoader::Material(QColor(QRgb(0xE0D0C0)));

	Qt3DCore::QTransform *testTransform = new Qt3DCore::QTransform();
	testTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), -135.0f));
	testTransform->setTranslation(QVector3D(19.0f, 6.0f, 15.0f));

	m_startScreen = new Qt3DCore::QEntity(m_rootEntity);
	m_startScreen->addComponent(testMesh);
	m_startScreen->addComponent(testMaterial);
	m_startScreen->addComponent(testTransform);

	qWarning("Start Screen Created");

}

void Graphics::gameOverScreen()
{
	Qt3DRender::QMesh *testMesh = ModelLoader::LoadMesh("../Assets/Mesh/GameOverText.obj");
	Qt3DExtras::QPhongMaterial *testMaterial = ModelLoader::Material(QColor(QRgb(0xE0D0C0)));

	Qt3DCore::QTransform *testTransform = new Qt3DCore::QTransform();
	testTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), -135.0f));
	testTransform->setTranslation(QVector3D(17.0f, 6.0f, 15.0f));

	m_gameOverScreen = new Qt3DCore::QEntity(m_rootEntity);
	m_gameOverScreen->addComponent(testMesh);
	m_gameOverScreen->addComponent(testMaterial);
	m_gameOverScreen->addComponent(testTransform);

	qWarning("Game Over Screen Created");
	m_gameOverScreen->setEnabled(false);

}

void Graphics::createPlayer()
{
	m_player = new Player(m_rootEntity);
}

void Graphics::createEnemy()
{
	m_enemy0 = new Enemy(m_rootEntity);
	m_enemy1 = new Enemy(m_rootEntity);
	m_enemy2 = new Enemy(m_rootEntity);
}

void Graphics::createMap()
{
	m_map = new Map(m_rootEntity);
}

void Graphics::UpdateGraphics()
{
}


Player * Graphics::GetPlayer()
{
	return m_player;
}

Enemy * Graphics::GetEnemy0()
{
	return m_enemy0;
}

Enemy * Graphics::GetEnemy1()
{
	return m_enemy1;
}

Enemy * Graphics::GetEnemy2()
{
	return m_enemy2;
}

void Graphics::SetRoot(Qt3DCore::QEntity * rootEntity)
{
	m_rootEntity = rootEntity;
}

void Graphics::SetStartScreen(bool isShowing)
{
	m_startScreen->setEnabled(isShowing);
}

void Graphics::SetGameOverScreen(bool isShowing)
{
	m_gameOverScreen->setEnabled(isShowing);
}
