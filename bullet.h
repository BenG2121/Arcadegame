#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QObject>

enum enBulletType{
    PlayerBullet,EnemyBullet,EnemyMissile
};



class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet();
    enBulletType bulletType;
    int bulletSpeed;
public slots:
    void move();
    void cooldown();
};

#endif // BULLET_H
