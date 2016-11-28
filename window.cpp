#include "window.h"
#include "renderarea.h"
#include "bodyclass.h"

#include <QtWidgets>
#include <QMouseEvent>

Window::Window(QWidget *parent) : QWidget(parent)
{
    setFixedSize(600,600);
    std::vector<BodyClass> bodies;
    renderArea = new RenderArea;
    plusButton = new QPushButton("+", this);
    minusButton = new QPushButton("-", this);

    connect(renderArea, SIGNAL(mousePressEvent()), this,  createBody(std::pair<int,int>));
}
void createBody(std::pair<int, int> coordinates)
{
    BodyClass newbody((float)coordinates.first, (float)coordinates.second, 0.0, 0.0, 100000.0);
    this->bodies.push_back(newbody);
}
