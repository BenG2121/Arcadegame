#include "MyRect.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QEvent>
#include "bullet.h"
#include <QDebug>

int iPlayerIncrementalStepSize = 5;

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            if ((pos().x() < iPlayerIncrementalStepSize)){
                setPos( 0 ,y());
            }
            else
            {
                setPos( x()-iPlayerIncrementalStepSize,y() );
            }
        }

    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x()+rect().width() < scene()->width()){
            if( scene()->width()-pos().x()-rect().width() < iPlayerIncrementalStepSize)
            {
            }
            else
            {
                setPos( x()+iPlayerIncrementalStepSize,y() );
            }
        }

    }

}
void MyRect::keyReleaseEvent(QKeyEvent *event)
{
    if( Revent->KeyRelease() == true ){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+rect().width()/2-bullet->rect().width()/2,y()-rect().width()/2);
        scene()->addItem(bullet);
    }
}

