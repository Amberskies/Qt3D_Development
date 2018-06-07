#pragma once

#include <Qt3DWindow>
#include <QEntity>
#include <QCamera>
#include <QPointLight>
#include <QTransform>
#include <QForwardRenderer>
#include <QMouseEvent>

class Window3D : public Qt3DExtras::Qt3DWindow
{
private:

	Q_OBJECT

public:
	Window3D(QScreen *parent = nullptr);
	~Window3D();
	void Update();
	// Gets
	void createPointLight(Qt3DCore::QEntity *root);
	Qt3DRender::QCamera* getCamera();
	// Sets
	void setBackgroundColor(QColor color);

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private:
	Qt3DRender::QCamera *cameraEntity;
	Qt3DCore::QEntity *lightEntity;
	Qt3DRender::QPointLight *light;
	Qt3DCore::QTransform *lightTransform;
};
