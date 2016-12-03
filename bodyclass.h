#ifndef BODYCLASS_H
#define BODYCLASS_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>

class BodyClass : public QGraphicsItem
{
    public:
        BodyClass(float initial_x, float initial_y, float initial_xv, float initial_yv, float initial_mass);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        QRectF boundingRect() const;
        float mass;
    protected:
        void advance(int phase);
    private:
        float pos_x, pos_y, xv, yv;
        void ChangePos(float new_x, float new_y);
        void AddVel(float new_xv, float new_yv);

};
#endif // BODYCLASS_H
