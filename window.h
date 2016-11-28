#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <vector>

class Window : public QWidget
{
    Q_OBJECT
    public:
        explicit Window(QWidget *parent = 0);
        std::vector<BodyClass> bodies;
    private:
        RenderArea *renderArea;
        QPushButton *plusButton;
        QPushButton *minusButton;
    signals:

    public slots:
       void BodyClass createBody(std::pair<int, int>);

};

#endif // WINDOW_H
