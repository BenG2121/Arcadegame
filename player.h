#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>

class MyRect: public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent * event);
    //void keyReleaseEvent(QKeyEvent * event);
    void counterEvent(QTimerEvent * event);
    int playerSpeed;
};

#endif // MYRECT_H
