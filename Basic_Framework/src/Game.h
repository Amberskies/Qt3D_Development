#pragma once

#include <QObject>
#include <QEntity>

#include "src/Rendering/Window3D.h"



class Game : public QObject
{
	Q_OBJECT

public:
	Game(class Window3D& window3D);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	void Go();

private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	Window3D& m_window3D;
	//Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
};
