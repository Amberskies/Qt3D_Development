#pragma once

#include <QEntity>
#include <QTransform>
#include <QExtrudedTextMesh>
#include <QPhongMaterial> 

class StartScreen
{
public:
	explicit StartScreen(Qt3DCore::QEntity *rootEntity);
	virtual ~StartScreen();

	void RemoveStart();
	void GameOver(QVector3D position);

private:
	Qt3DCore::QEntity *m_rootEntity = nullptr;
	Qt3DCore::QEntity *m_startScreen = nullptr;

	Qt3DExtras::QExtrudedTextMesh *m_textMesh = nullptr;
	Qt3DExtras::QPhongMaterial *m_textMaterial = nullptr;
	Qt3DCore::QTransform *m_textTransform = nullptr;
};