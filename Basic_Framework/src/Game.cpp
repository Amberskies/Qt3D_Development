#include "Game.h"




Game::Game(Window3D & window3D) :
	m_window3D(window3D)
{
	gfx.SetRoot(m_window3D.getSceneRoot());
	
	m_window3D.show();

	qWarning("Game Created");
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
	gfx.createPlayer();
	gfx.createMap();
}

void Game::UpdateModel()
{
	m_window3D.Update(); // Updates user input to the Window
	gfx.UpdateGraphics();

	
}
