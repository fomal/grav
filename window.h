#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <vector>
#include <QPushButton>
#include <QMouseEvent>
#include <QtWidgets>

#include <iostream>

class Window : public QWidget
{
    Q_OBJECT
    public:
        explicit Window(QWidget *parent = 0);
    private:
        QTimer *timer;
        QGraphicsView *view;
        QGraphicsScene *scene;
        QPushButton *plusButton;
        QPushButton *minusButton;
    signals:

    public slots:
       void createBody(int, int);

};

#endif // WINDOW_H
