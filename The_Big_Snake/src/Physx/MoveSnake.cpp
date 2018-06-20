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
	m_segments[0] = m_snake->GetPlayerPosition();
	m_currentRotation = m_snake->GetPlayerRotation();

	if (Input::keyPressed(Qt::Key_Left) && !m_inhibitLeft)
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

		m_inhibitLeft = true;
	}
	else if (Input::keyPressed(Qt::Key_Right) && !m_inhibitRight)
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

		m_inhibitRight = true;
	}

	if (Input::keyReleased(Qt::Key_Left))
	{
		m_inhibitLeft = false;
	}
	if (Input::keyReleased(Qt::Key_Right))
	{
		m_inhibitRight = false;
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
	--m_countdown;
	// Test ////////////////////////////////
	if (Input::keyReleased(Qt::Key_Space))
	{
		m_currentSegments++;
		m_snake->Grow(m_currentSegments, m_segments[m_currentSegments - 1]);
		m_segments[m_currentSegments] = m_segments[m_currentSegments - 1];
		m_moveSpeed -= 0.2f;
	}
	//******///////////////////////////////


	if (m_countdown <= 0)
	{
		// move segments here
		int i = m_currentSegments;
		while (i > 0)
		{
			m_snake->SetSegmentPosition(i, m_segments[i - 1]);
			m_segments[i] = m_segments[i - 1];
			i--;
		}

		m_snake->SetPlayerPosition(m_segments[0] + m_moveDirection);
		m_camera->translateWorld(m_moveDirection);

		m_countdown = m_moveSpeed;
	}
}
