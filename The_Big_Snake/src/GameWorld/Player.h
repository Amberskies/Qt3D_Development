#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QEntity>
#include <QTransform>
#include <QMesh>
#include <QPhongMaterial> 
#include <QObjectPicker>

class Player : public QObject
{
    Q_OBJECT

public:
	explicit Player(Qt3DCore::QEntity *rootEntity);
	virtual ~Player();

	// getters
	Qt3DCore::QEntity *GetPlayer();
	QVector3D GetPlayerPosition();
	float GetPlayerRotation();
	Qt3DRender::QObjectPicker *GetPlayerSelector();

	//setters
	void SetPlayerRotaion(QVector3D axis, float angle);
	void SetPlayerPosition(QVector3D playerPosition);
	void SetPlayerColor(QColor playerColor);
private:
	Qt3DCore::QEntity *m_rootEntity;
	Qt3DCore::QEntity *m_player;

	Qt3DRender::QMesh *m_mesh = nullptr;
	Qt3DExtras::QPhongMaterial *m_material = nullptr;
	Qt3DCore::QTransform *m_transform = nullptr;
	Qt3DRender::QObjectPicker *m_picker = nullptr;
};

#endif // PLAYER_H
