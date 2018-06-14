#include "Game.h"

#include "src/GameRules/Dice.h"
#include "src/Core/Input.h"

Game::Game(Window3D & window3D) :
	m_window3D(window3D)
	, m_timer(new QTimer(this))
	, m_physics(new Physics(window3D, m_gfx))
{
	Dice::InitializeDice();
	// Take the root of the main window and give it to the Graphics
	m_gfx.SetRoot(m_window3D.getSceneRoot());
	
	m_gfx.startScreen();
	m_gfx.gameOverScreen();
	m_gfx.createPlayer();
	m_gfx.createEnemy();
	m_gfx.createMap();

	m_physics->InitializePhysics();
	m_gameState = 0;
	// connect the main Game Loop
	connect(m_timer, SIGNAL(timeout()), this, SLOT(MainGameLoop()));
	qWarning("Game Created");
}

Game::~Game()
{
	delete m_physics;
	delete m_timer;
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
		if (m_gameState == 0)
		{
			ShowStartScreen();
		}
		else if(m_gameState == 1)
		{
			m_gfx.BeginFrame();
			UpdateModel();
			ComposeFrame();
			m_gfx.EndFrame();
		}
		else if(m_gameState == 2)
		{
			m_window3D.Update(); // Updates user input to the Window

			if (Input::keyPressed(Qt::Key_Return))
			{
				exit(0);
			}
		}
		else
		{
			qWarning("Game State is out of bounds.");
		}
	}
	

	m_timer->start(10);

}

void Game::ComposeFrame()
{
	m_window3D.Update(); // Updates user input to the Window
	m_physics->UpdatePhysics(); // Updates all Physical Objects/Entities

	int score = m_physics->GetScore();
	if (score == 3)
	{
		m_gameState = 2;
		m_gfx.SetGameOverScreen(true);
	}
}

void Game::UpdateModel()
{
	m_gfx.UpdateGraphics();

	
}

void Game::ShowStartScreen()
{
	m_window3D.Update(); // Updates user input to the Window
	if (Input::keyPressed(Qt::Key_Return)) 
	{
		m_gameState = 1;;
		m_gfx.SetStartScreen(false);
		qWarning("Start Screen Closed");
	}
}
