#include "MoveSnake.h"
#include "src/Core/Input.h"

MoveSnake::MoveSnake()
{
	// Empty
}

MoveSnake::~MoveSnake()
{
	// Empty
}

void MoveSnake::UpdateMoveSnake(Player *snake, Qt3DRender::QCamera *camera)
{
	m_snake = snake;
	m_camera = camera;
	m_currentPosition = m_snake->GetPlayerPosition();

	if (Input::keyPressed(Qt::Key_Left))
	{
		// turn left

		// south = 0, 0, 1
		// east = 1, 0, 0
		// north = 0, 0, -1
		// west = -1, 0, 0
	}
	else if (Input::keyPressed(Qt::Key_Right))
	{
		// turn right

		// south = 0, 0, 1
		// west = -1, 0, 0
		// north = 0, 0, -1
		// east = 1, 0, 0
	}

	FinalMovement();
}

bool MoveSnake::checkCollision()
{
	bool notCollided = true;
	QVector3D pos = m_snake->GetPlayerPosition();
	if (pos.x() <= 0.4f ||
		pos.x() >= 29.6f ||
		pos.z() <= 0.4f ||
		pos.z() >= 29.6f) notCollided = false;

	return notCollided;
}

///////////////////////////Private///////////////

void MoveSnake::FinalMovement()
{
	m_snake->SetPlayerPosition( m_currentPosition + (m_moveDirection * m_moveSpeed));
	m_camera->translateWorld(m_moveDirection * m_moveSpeed);
	
}
