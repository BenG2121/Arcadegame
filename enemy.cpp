#include "enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QtMath>
#include "bullet.h"

float frequency = 0;
float frequency_rad;
Enemy::Enemy()
{
    setRect(0,0,150,150);
    setBrush(Qt::NoBrush);
    setPen(QPen(Qt::red));
    //connect Method
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveSine()));
    timer->start(100);
    QTimer * shotTimer = new QTimer();
    connect(shotTimer,SIGNAL(timeout()),this,SLOT(shootBullets()));
    shotTimer->start(2000);
    QTimer * shotMissileTimer = new QTimer();
    connect(shotMissileTimer,SIGNAL(timeout()),this,SLOT(shootMissile()));
    shotMissileTimer->start(20000);
}
void Enemy::moveSine()
{
    frequency = frequency + 1;
    frequency_rad = qDegreesToRadians(frequency);
    setPos(x()+ 5*qCos(frequency_rad),y());
}
void Enemy::shootBullets()
{
    int sideBulletOffset = 10;
    // create a bullet
    Bullet * enemyBulletLeft = new Bullet();
    enemyBulletLeft->setPos(x()+sideBulletOffset,y()+rect().width());
    enemyBulletLeft->bulletType = EnemyBullet;
    scene()->addItem(enemyBulletLeft);

    Bullet * enemyBulletRight = new Bullet();
    enemyBulletRight->setPos(x()+rect().width()-sideBulletOffset,y()+rect().width());
    enemyBulletRight->bulletType = EnemyBullet;
    scene()->addItem(enemyBulletRight);
}

void Enemy::shootMissile()
{
    Bullet * enemyBulletLeft = new Bullet();
    enemyBulletLeft->setPos(x()+rect().width()/2,y()+rect().width());
    enemyBulletLeft->bulletType = EnemyMissile;
    scene()->addItem(enemyBulletLeft);
}
