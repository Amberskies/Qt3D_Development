#include "Goal.h"
#include "src/Core/ModelLoader.h"

Goal::Goal(Qt3DCore::QEntity *rootEntity) 
	: m_rootEntity(rootEntity)
{
	m_goalMesh = ModelLoader::LoadMesh("../Assets/Player/Player1.ply");
	m_goalMaterial = ModelLoader::Material(m_color);

	QVector3D pos = { 15.0f, 0.5f, 15.0f };

	addGoal(m_numGoals, pos);
	m_numGoals++;
}

Goal::~Goal()
{
	// Empty
}

void Goal::InitializeGoal()
{
	// EmptyS
}

void Goal::addGoal(int i,QVector3D position)
{
	m_goalTransform[i] = new Qt3DCore::QTransform();
	m_goalTransform[i]->setTranslation(position);

	m_goal[i] = new Qt3DCore::QEntity(m_rootEntity);
	m_goal[i]->addComponent(m_goalMesh);
	m_goal[i]->addComponent(m_goalMaterial);
	m_goal[i]->addComponent(m_goalTransform[i]);
}

QVector3D Goal::GetGoalPosition(int i)
{
	return m_goalTransform[i]->translation();
}

void Goal::SetGoalPosition(int i, QVector3D position)
{
	m_goalTransform[i]->setTranslation(position);
}
