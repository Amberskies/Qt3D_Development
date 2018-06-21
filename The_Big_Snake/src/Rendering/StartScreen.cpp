#include "StartScreen.h"
#include "src/Core/ModelLoader.h"



StartScreen::StartScreen(Qt3DCore::QEntity * rootEntity) 
	: m_rootEntity(rootEntity)
{
	m_startScreen = new Qt3DCore::QEntity(m_rootEntity);

	m_textMesh = new Qt3DExtras::QExtrudedTextMesh();
	m_textMesh->setDepth(0.4f);
	//m_textMesh->setFont(const QFont &font);
	m_textMesh->setText("Welcome to THE BIG SNAKE ! Press ENTER to Start.");

	m_textMaterial = ModelLoader::Material(QColor(QRgb(0xEEAA10)));

	m_textTransform = new Qt3DCore::QTransform();
	m_textTransform->setTranslation(QVector3D(20.0f, 10.0f, 0.0f));
	m_textTransform->setRotationY(-135.0f);
	m_textTransform->setRotationX(-25.0f);

	m_startScreen->addComponent(m_textMesh);
	m_startScreen->addComponent(m_textMaterial);
	m_startScreen->addComponent(m_textTransform);
}

StartScreen::~StartScreen()
{
	delete m_textTransform;
	delete m_textMaterial;
	delete m_textMesh;
	delete m_startScreen;
}

void StartScreen::RemoveStart()
{
	m_startScreen->setEnabled(false);
}

void StartScreen::GameOver(QVector3D position)
{
	QVector3D pos;
	pos.setX(position.x() + 5.0f);
	pos.setY(position.y() + 5.0f);
	pos.setZ(position.z());

	m_textMesh->setText(" GAME OVER !");
	m_textTransform->setTranslation(pos);
	m_startScreen->setEnabled(true);
}
