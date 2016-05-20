#include "bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include "enemy.h"



Bullet::Bullet()
{

    //connect Method
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);


}

void Bullet::move()
{
    // move bullet up#
    if (Bullet::bulletType == PlayerBullet)
    {
        // drew rect
        bulletSpeed = 12;
        setRect(0,0,10,50);
        setPen(QPen(Qt::green,4));
        setBrush(Qt::NoBrush);

        setPos(x(),y()-bulletSpeed);
        if(pos().y() + rect().height() < 0)
        {
            scene()->removeItem(this);
            delete this;
        }
    }
    else if (Bullet::bulletType == EnemyBullet)
    {
        // drew rect
        bulletSpeed = 8;
        setRect(0,0,5,bulletSpeed);
        setBrush(Qt::red);

        setPos(x(),y()+ 10);
        if(pos().y()  >  scene()->height())
        {
            scene()->removeItem(this);
            delete this;
        }
    }
    else if (Bullet::bulletType == EnemyMissile)
    {
        // drew rect
        bulletSpeed = 2;
        setRect(0,0,10,50);
        setPen(QPen(Qt::red,1));
        setBrush(Qt::NoBrush);

        setPos(x(),y()+ bulletSpeed);
        if(pos().y()  >  scene()->height())
        {
            scene()->removeItem(this);
            delete this;
        }
    }
}
void Bullet::cooldown()
{


}


