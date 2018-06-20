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

	void Grow(int segment, QVector3D location);

	// getters
	Qt3DCore::QEntity *GetPlayer();
	QVector3D GetPlayerPosition();
	float GetPlayerRotation();
	Qt3DRender::QObjectPicker *GetPlayerSelector();

	//setters
	void SetPlayerRotaion(QVector3D axis, float angle);
	void SetPlayerPosition(QVector3D playerPosition);
	void SetPlayerColor(QColor playerColor);
	void SetSegmentPosition(int segment, QVector3D segmentPosition);

private:
	Qt3DCore::QEntity *m_rootEntity;
	Qt3DCore::QEntity *m_player;
	Qt3DCore::QEntity *m_segment[100];

	Qt3DRender::QMesh *m_mesh = nullptr;
	Qt3DExtras::QPhongMaterial *m_material = nullptr;
	Qt3DRender::QObjectPicker *m_picker = nullptr;

	QColor m_color = QColor(QRgb(0xEEAA10));
	Qt3DRender::QMesh *m_segMesh = nullptr;
	Qt3DExtras::QPhongMaterial *m_segMaterial = nullptr;
	Qt3DCore::QTransform *m_segTransform[100];
};

#endif // PLAYER_H
