#include "Game.h"


Game::Game(Window3D & window3D) :
	m_window3D(window3D)
	, m_gfx(new Graphics(window3D))
	, m_timer(new QTimer(this))
{
	// Take the root from the main window and give it to the Graphics
	m_gfx->SetRoot(m_window3D.getSceneRoot());
	
	m_gfx->createPlayer();
	m_gfx->createMap();

	// connect the main Game Loop
	connect(m_timer, SIGNAL(timeout()), this, SLOT(MainGameLoop()));
	qWarning("Game Created");
}

Game::~Game()
{
	delete m_timer;
	delete m_gfx;
	qWarning("Game Destroyed");
}

void Game::Go()
{
	m_timer->start(10);
}

void Game::MainGameLoop()
{
	m_timer->stop();

	m_gfx->BeginFrame();
	UpdateModel();
	ComposeFrame();
	m_gfx->EndFrame();

	m_timer->start(10);

}

void Game::ComposeFrame()
{
	// Empty
}

void Game::UpdateModel()
{
	m_window3D.Update(); // Updates user input to the Window
	m_gfx->UpdateGraphics();

	
}
