#include "window.h"

#include <QtGui>
#include <QtCore>
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    //Q_INIT_RESOURCE(basicdrawing);
    QApplication app(argc, argv);

    Window window;
    window.show();

    return app.exec();

}
