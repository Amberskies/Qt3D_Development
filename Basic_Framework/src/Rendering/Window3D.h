#pragma once

#include <Qt3DWindow>
#include <QEntity>
#include <QCamera>
#include <QPointLight>
#include <QTransform>
#include <QForwardRenderer>
#include <QMouseEvent>
#include <QKeyEvent>

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
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);

private:
	Qt3DRender::QCamera *m_cameraEntity;
	Qt3DCore::QEntity *m_lightEntity;
	Qt3DRender::QPointLight *m_light;
	Qt3DCore::QTransform *m_lightTransform;
};
