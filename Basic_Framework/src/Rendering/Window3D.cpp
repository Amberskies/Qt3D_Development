#include "Window3D.h"
#include "src/Core/Input.h"

Window3D::Window3D(QScreen *parent)
	: Qt3DWindow(parent)
{
	qWarning("Window 3D : Created");
}

Window3D::~Window3D()
{
	qWarning("Window 3D : Destroyed");
}

void Window3D::Update()
{
	Input::update();
}

Qt3DRender::QCamera *Window3D::getCamera()
{
	cameraEntity = this->camera();
	cameraEntity->lens()->setPerspectiveProjection(44.0f, 4.0f / 3.0f, 0.1f, 1000.0f);
	cameraEntity->translate(QVector3D(0.0f, 30.0f, 0.0f));
	cameraEntity->setUpVector(QVector3D(0.0f, 1.0f, 0.0f));
	cameraEntity->setViewCenter(QVector3D(15.0f, 0.0f, 15.0f));
	return cameraEntity;
}

void Window3D::createPointLight(Qt3DCore::QEntity *root)
{
	// Light ( placed at cameras initial position for 'convenience'
	// It can be paced anywhere with setTranslation(QVector3D(x, y, z)
	lightEntity = new Qt3DCore::QEntity(root);
	light = new Qt3DRender::QPointLight(lightEntity);
	light->setColor("white");
	light->setIntensity(1);
	lightEntity->addComponent(light);
	lightTransform = new Qt3DCore::QTransform(lightEntity);
	lightTransform->setTranslation(cameraEntity->position());
	lightEntity->addComponent(lightTransform);
}

void Window3D::setBackgroundColor(QColor color)
{
	this->defaultFrameGraph()->setClearColor(QColor(color));
}

void Window3D::mousePressEvent(QMouseEvent *event)
{
	Input::registerMousePress(event->button());
}

void Window3D::mouseReleaseEvent(QMouseEvent *event)
{
	Input::registerMouseRelease(event->button());
}

