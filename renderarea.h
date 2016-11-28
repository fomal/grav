#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QMouseEvent>

class renderArea : public QWidget
{
    Q_OBJECT
public:
    explicit renderArea(QWidget *parent = 0);

signals:
    std::pair<int, int> renderArea::mousePressEvent(QMouseEvent *event);
public slots:
};

#endif // RENDERAREA_H
