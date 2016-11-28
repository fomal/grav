TEMPLATE = app
TARGET = grav
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    window.h \
    renderarea.h \
    bodyclass.h

SOURCES += \
    window.cpp \
    main.cpp \
    renderarea.cpp \
    bodyclass.cpp
