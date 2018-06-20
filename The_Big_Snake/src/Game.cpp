#include "Game.h"

Game::Game(Window3D & window3D) :
	m_window3D(window3D)
	, m_gfx(new Graphics())
	, m_gameLogic(new GameLogic(m_gfx, m_window3D))
{
	// Take the root from the main window and give it to the Graphics
	m_gfx->InitializeGraphics(m_window3D.GetSceneRoot());
	m_gameLogic->InititializeGameLogic();
	// connect the main Game Loop
	connect(&m_timer, SIGNAL(timeout()), this, SLOT(MainGameLoop()));
}

Game::~Game()
{
	delete m_gameLogic;
	delete m_gfx;
}

void Game::Go()
{
	// setRootEntity starts the Qt3D engine.
	m_window3D.setRootEntity(m_window3D.GetSceneRoot());
	m_timer.start(10);
}

void Game::MainGameLoop()
{
	m_timer.stop();

	if (m_window3D.isExposed())
	{
		if (m_gameState == 0)
		{
			m_gameState = m_gameLogic->StartScreen();
		}
		else if (m_gameState == 1)
		{
			UpdateModel();
			ComposeFrame();
		}
		else if (m_gameState == 2)
		{
			m_gameState = m_gameLogic->GameOver();
		}
		else
		{
			qWarning("m_gameState went out of bounds.");
		}
	}
	
	m_timer.start(10);
}

void Game::UpdateModel()
{
	m_window3D.Update(); // Updates user input to the Window
	m_gameLogic->UpdateGameLogic();
}

void Game::ComposeFrame()
{
	m_gfx->UpdateGraphics();
}

