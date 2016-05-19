/* Prereqs
 * QGraphicsScene (GameWorld)           Information/Bunch of objects
 * QGraphicsItem (Player)(QGraphicsRectItem)
 * QGraphicsView (Widget)               Visualizes scene
*/

#include <QApplication>
#include <QGraphicsScene>
#include <MyRect.h>
#include <QGraphicsView>
#include <QAbstractGraphicsShapeItem>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene);
    QBrush *sceneBrush = new QBrush( Qt::black);
    // create an item to put into the scene
    MyRect * player = new MyRect();

    // add the item to the scene
    player->setRect(0,0,100,100);
    player->setBrush(Qt::NoBrush);
    player->setPen(QPen(Qt::green,4,Qt::SolidLine,Qt::SquareCap,Qt::BevelJoin));
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // scene
    scene->setSceneRect(0,0,1024,678);

    // add a view
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(1024,678);
    view->setBackgroundBrush(*sceneBrush);

    // adjust player position in reference to view
    player->setPos(view->width()/2-player->rect().width()/2, view->height() - player->rect().height());

    return a.exec();
}
