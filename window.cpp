#include "window.h"
#include "bodyclass.h"
#include "mygraphicsscene.h"


Window::Window(QWidget *parent) : QWidget(parent)
{
    setFixedSize(600,600);

    view = new QGraphicsView;
    scene = new MyGraphicsScene();
    scene->setSceneRect(-300, -300, 300, 300);
    scene->setBackgroundBrush(Qt::black);
    view->setScene(scene);
    this->resize(300,300);
    view->show();

    //QPushButton *plusButton = new QPushButton("+", this);
    //QPushButton *minusButton = new QPushButton("-", this);

    connect(scene, SIGNAL(sendcoord(int, int)), this, SLOT(createBody(int, int)));

    timer = new QTimer(this);
    // every time the signal times out, the scene tells its shit to advance a step
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(30);
}
void Window::createBody(int new_x, int new_y)
{
    //float new_x = (float)mouseEvent->pos().x();
    //float new_y = (float)mouseEvent->pos().y();
    QGraphicsItem *newbody = new BodyClass((float)new_x, (float)new_y, 0.0, 0.0, 100000.0);
    //std::cout << "asdf" << std::endl;
    this->scene->addItem(newbody);
}
