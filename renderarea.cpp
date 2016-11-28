#include "renderarea.h"

renderArea::renderArea(QWidget *parent) : QWidget(parent)
{

}
std::pair<int, int> renderArea::mousePressEvent(QMouseEvent *event)
{
   int x_pos = ev->x();
   int y_pos = ev->y();
   return (makepair(x_pos, y_pos));

}
