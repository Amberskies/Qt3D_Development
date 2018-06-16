#pragma once

#include <Qt3DWindow>
#include <QEntity>
#include <QCamera>
#include <QPointLight>
#include <QTransform>
#include <QForwardRenderer>
#include <QMouseEvent>
#include <QKeyEvent>


#include "src/Rendering/FPS_Component/FpsMonitor.h"

class Window3D : public Qt3DExtras::Qt3DWindow
{
private:

	Q_OBJECT

public:
	explicit Window3D(QScreen *parent = nullptr);
	~Window3D();
	void Update();
	void InitializeWindow3D();

	// Gets
	Qt3DRender::QCamera* GetCamera();
	Qt3DCore::QEntity* GetSceneRoot();
	Qt3DCore::QEntity* GetPointLight();
	Qt3DCore::QEntity* GetFps();
	// Sets
	void SetBackgroundColor(QColor color);

protected:
	// inherited from QWindow.
	void mousePressEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
	void keyPressEvent(QKeyEvent *event) override;
	void keyReleaseEvent(QKeyEvent *event) override;

private:
	Qt3DCore::QEntity *m_sceneRoot = nullptr;
	Qt3DRender::QCamera *m_cameraEntity = nullptr;
	Qt3DCore::QEntity *m_lightEntity = nullptr;
	Qt3DRender::QPointLight *m_light = nullptr;
	Qt3DCore::QTransform *m_lightTransform = nullptr;
	Qt3DCore::QEntity *m_fps = nullptr;
};
