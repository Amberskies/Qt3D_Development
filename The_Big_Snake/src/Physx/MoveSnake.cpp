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
	m_currentRotation = m_snake->GetPlayerRotation();

	if (Input::keyReleased(Qt::Key_Left))
	{
		QVector3D axis = { 0.0f, 1.0f, 0.0f };
		float angle = m_currentRotation + 90.0f;
		if (m_currentRotation >= 360.0f) m_currentRotation = 0.0f;
		m_snake->SetPlayerRotaion(axis, angle);

		// south = 0, 0, 1
		if (m_moveDirection.z() == 1.0f) m_moveDirection = QVector3D(1.0f, 0.0f, 0.0f);
		// east = 1, 0, 0
		else if (m_moveDirection.x() == 1.0f) m_moveDirection = QVector3D(0.0f, 0.0f, -1.0f);
		// north = 0, 0, -1
		else if (m_moveDirection.z() == -1.0f) m_moveDirection = QVector3D(-1.0f, 0.0f, 0.0f);
		// west = -1, 0, 0
		else if (m_moveDirection.x() == -1.0f) m_moveDirection = QVector3D(0.0f, 0.0f, 1.0f);
	}
	else if (Input::keyReleased(Qt::Key_Right))
	{
		QVector3D axis = { 0.0f, 1.0f, 0.0f };
		float angle = m_currentRotation - 90.0f;
		if (m_currentRotation <= -360.0f) m_currentRotation = 0.0f;
		m_snake->SetPlayerRotaion(axis, angle);

		// south = 0, 0, 1
		if (m_moveDirection.z() == 1.0f) m_moveDirection = QVector3D(-1.0f, 0.0f, 0.0f);
		// west = -1, 0, 0
		else if (m_moveDirection.x() == -1.0f) m_moveDirection = QVector3D(0.0f, 0.0f, -1.0f);
		// north = 0, 0, -1
		else if (m_moveDirection.z() == -1.0f) m_moveDirection = QVector3D(1.0f, 0.0f, 0.0f);
		// east = 1, 0, 0
		else if (m_moveDirection.x() == 1.0f) m_moveDirection = QVector3D(0.0f, 0.0f, 1.0f);
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

///////////////////////////Private////////////////////////////

void MoveSnake::FinalMovement()
{
	m_snake->SetPlayerPosition( m_currentPosition + (m_moveDirection * m_moveSpeed));
	m_camera->translateWorld(m_moveDirection * m_moveSpeed);
	
}
