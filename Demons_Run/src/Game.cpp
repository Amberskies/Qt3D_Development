#include "Game.h"


Game::Game(Window3D & window3D) :
	m_window3D(window3D)
	, m_gfx(new Graphics())
	, m_timer(new QTimer(this))
	, m_physics(new Physics(window3D))
{
	// Take the root of the main window and give it to the Graphics
	m_gfx->SetRoot(m_window3D.getSceneRoot());
	
	m_gfx->createPlayer();
	m_physics->setPlayer(m_gfx->GetPlayer());

	m_gfx->createMap();

	// connect the main Game Loop
	connect(m_timer, SIGNAL(timeout()), this, SLOT(MainGameLoop()));
	qWarning("Game Created");
}

Game::~Game()
{
	delete m_physics;
	delete m_timer;
	delete m_gfx;
	qWarning("Game Destroyed");
}

void Game::Go()
{
	// setRootEntity starts the Qt3D engine.
	m_window3D.setRootEntity(m_window3D.getSceneRoot());
	m_timer->start(10);
}

void Game::MainGameLoop()
{
	m_timer->stop();

	if (m_window3D.isExposed())
	{
		m_gfx->BeginFrame();
		UpdateModel();
		ComposeFrame();
		m_gfx->EndFrame();
	}
	m_timer->start(10);

}

void Game::ComposeFrame()
{
	m_window3D.Update(); // Updates user input to the Window
	m_physics->UpdatePhysics(); // Updates all Physical Objects/Entities
}

void Game::UpdateModel()
{
	m_gfx->UpdateGraphics();

	
}
