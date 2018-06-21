#pragma once

#include <QEntity>
#include <QTransform>
#include <QMesh>
#include <QPhongMaterial> 

class Goal
{
public:
	explicit Goal(Qt3DCore::QEntity *rootEntity);
	virtual ~Goal();

	void InitializeGoal();
	void addGoal(int i, QVector3D position);

	// Getters
	QVector3D GetGoalPosition(int i);
	// Setters
	void SetGoalPosition(int i, QVector3D position);
private:
	Qt3DCore::QEntity *m_rootEntity = nullptr;
	Qt3DCore::QEntity *m_goal[100];

	QColor m_color = QColor(QRgb(0xEE0000));
	Qt3DRender::QMesh *m_goalMesh = nullptr;
	Qt3DExtras::QPhongMaterial *m_goalMaterial = nullptr;
	Qt3DCore::QTransform *m_goalTransform[100];

	int m_numGoals = 0;
};