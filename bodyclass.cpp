#include "bodyclass.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
//using namespace std;

/* class BodyClass : public QGraphicsItem
{
    public:
        BodyClass(float initial_x, float initial_y, float initial_xv, float initial_yv, float initial_mass);
        void ChangePos(float, float);
        void AddVel(float, float);
        pair<float, float> GetPos();
        float pos_x, pos_y, xv, yv, mass;
    protected:
        void advance(int phase);+
    private:

}; */
BodyClass::BodyClass(float initial_x, float initial_y, float initial_xv, float initial_yv, float initial_mass)
{
    this->pos_x = initial_x;
    this->pos_y = initial_y;
    this->xv = initial_xv;
    this->yv = initial_yv;
    this->mass = initial_mass;
    setPos(mapToParent(this->pos_x, this->pos_y));
    this->setVisible(true);

    //cout << "constructed a body at " << this->pos_x << "," << this->pos_y << endl;
}
QRectF BodyClass::boundingRect() const
{
    return QRect(0,0,5,5);
}

void BodyClass::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::white, 5);
    QRectF rect = boundingRect();
    painter->setPen(pen);
    painter->drawEllipse(rect);
}

void BodyClass::ChangePos(float new_x, float new_y)
{
    this->pos_x += new_x;
    this->pos_y += new_y;
}
void BodyClass::AddVel(float new_xv, float new_yv)
{
    this->xv += new_xv;
    this->yv += new_yv;
}
void BodyClass::advance(int phase)
{
    if (!phase)
        return;
    QGraphicsScene *parentScene = this->scene();
    this->setVisible(false);
    QList<QGraphicsItem *> bodies = parentScene->items();
    for (int i = 0; i < bodies.size(); i++)
    {
        if (bodies[i]->isVisible())
        {
            // dis is wher we physics
            float G = 1e-5;
            float x1 = this->pos_x;
            float y1 = this->pos_y;
            float x2 = bodies[i]->x();
            float y2 = bodies[i]->y();
            float dist = sqrt(pow((x1-x2),2) + pow((y1-y2),2)) + 1.0;
            this->AddVel((G * this->mass / pow(dist, 2)*(x2 - x1)) , (G * this->mass / pow(dist, 2)*(y2 - y1)));
        }
    }
    this->setVisible(true);
    this->ChangePos(this->xv, this->yv);
    //setPos(mapToParent(this->pos_x, this->pos_y));
    setPos(mapToParent(this->xv, this->yv));
    //std::cout << "x: " << this->pos_x << " y:" << this->pos_y << std::endl;

}
