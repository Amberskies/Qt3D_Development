#ifndef MOVEPLAYER_H
#define MOVEPLAYER_H

#include <QEntity>
#include <QCamera>
#include <QVector2D>



class MovePlayer
{
    QVector2D moveto;
    QVector2D move;
    float faceto;
    float face;
public:
    MovePlayer();
    bool setMovePlayer(QPoint mousePos, QPoint centerPos);
    bool updatePlayerMovement(Qt3DCore::QEntity *player, Qt3DRender::QCamera *camera);
};

#endif // MOVEPLAYER_H
