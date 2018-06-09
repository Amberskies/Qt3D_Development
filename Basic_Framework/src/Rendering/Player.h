#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QEntity>


class Player : public QObject
{
    Q_OBJECT

    Qt3DCore::QEntity *m_rootEntity;
    Qt3DCore::QEntity *m_player;
public:
    explicit Player(Qt3DCore::QEntity *rootEntity);
    virtual ~Player();

    Qt3DCore::QEntity *getPlayer();

signals:

public slots:
};

#endif // PLAYER_H
