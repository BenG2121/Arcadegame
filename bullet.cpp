#include "bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>

Bullet::Bullet()
{
    // drew rect
    setRect(0,0,10,50);
    setPen(QPen(Qt::green,4));
    setBrush(Qt::NoBrush);
    //connect Method
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);


}

void Bullet::move()
{
    // move bullet up
    setPos(x(),y()-10);
    if(pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }


}
void Bullet::cooldown()
{


}


