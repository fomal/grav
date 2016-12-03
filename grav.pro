TEMPLATE = app
TARGET = grav
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    window.h \
    bodyclass.h \
    mygraphicsscene.h

SOURCES += \
    window.cpp \
    main.cpp \
    bodyclass.cpp \
    mygraphicsscene.cpp
