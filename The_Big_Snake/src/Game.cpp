#include "Game.h"
#include "src/Core/Input.h"

Game::Game(Window3D & window3D) :
	m_window3D(window3D)
	, m_gfx(new Graphics())
	, m_gameLogic(new GameLogic(m_gfx, m_window3D))
{
	// Take the root from the main window and give it to the Graphics
	m_gfx->InitializeGraphics(m_window3D.GetSceneRoot());
	
	// start those Brains going.
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
	m_startScreen = new StartScreen(m_window3D.GetSceneRoot());
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
			m_window3D.Update();
			if (Input::keyPressed(Qt::Key_Return))
			{
				m_startScreen->RemoveStart();
				m_gameState = 1;
			}
		}
		else if (m_gameState == 1)
		{
			UpdateModel();
			ComposeFrame();
		}
		else if (m_gameState == 2)
		{
			m_startScreen->GameOver(m_gfx->GetPlayer()->GetPlayerPosition());
			
			m_window3D.Update();
			if (Input::keyPressed(Qt::Key_Return))
			{
				exit(0);
			}
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
	if (m_gameLogic->UpdateGameLogic()) m_gameState = 2;
}

void Game::ComposeFrame()
{
	m_gfx->UpdateGraphics();
}

