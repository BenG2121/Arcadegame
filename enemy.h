#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include "bullet.h"

class Enemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemy();

public slots:
    void moveSine();
    void shootBullets();
    void shootMissile();

};

#endif // ENEMY_H
