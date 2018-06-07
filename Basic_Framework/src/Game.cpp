#include "Game.h"




Game::Game(Window3D & window3D) :
	m_window3D(window3D)
{
	m_window3D.show();
	gfx.SetRoot(m_window3D.getSceneRoot());
	qWarning("Game Created");

	m_window3D.setRootEntity(m_window3D.getSceneRoot());
}



void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::ComposeFrame()
{
	gfx.test();
}

void Game::UpdateModel()
{
	m_window3D.Update(); // Updates user input to the Window
}
