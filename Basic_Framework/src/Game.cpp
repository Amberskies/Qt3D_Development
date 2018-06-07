#include "Game.h"




Game::Game(Window3D & window3D) :
	m_window3D(window3D)
{
	m_window3D.show();
}



void Game::Go()
{
	//gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	//gfx.EndFrame();
}

void Game::ComposeFrame()
{
	// Empty
}

void Game::UpdateModel()
{
	// Empty
}
