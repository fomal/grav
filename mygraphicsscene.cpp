#include "mygraphicsscene.h"

MyGraphicsScene::MyGraphicsScene(QObject *parent) : QGraphicsScene(parent)
{
    this->setBackgroundBrush(Qt::gray);
}
void MyGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
}
void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  emit sendcoord(event->scenePos().x(),event->scenePos().y());
}
void MyGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}

