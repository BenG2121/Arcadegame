#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QEvent>
#include "bullet.h"
#include <QDebug>



void MyRect::keyPressEvent(QKeyEvent *event)
{
    playerSpeed = 10;
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            if ((pos().x() < playerSpeed)){
                setPos( 0 ,y());
            }
            else
            {
                setPos( x()-playerSpeed,y() );
            }
        }

    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x()+rect().width() < scene()->width()){
            if( scene()->width()-pos().x()-rect().width() < playerSpeed)
            {
            }
            else
            {
                setPos( x()+playerSpeed,y() );
            }
        }
    }
    else if( event->key() == Qt::Key_Space ){
            // create a bullet
            Bullet * bullet = new Bullet();
            bullet->setPos(x()+rect().width()/2-bullet->rect().width()/2,y()-rect().width()/2);
            bullet->bulletType = PlayerBullet;
            scene()->addItem(bullet);

    }

}


