TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Eventloop.cpp \
    Pthreadpool.cpp \
    Status.cpp

HEADERS += \
    Eventloop.h \
    Pthreadpool.h \
    Status.h

INCLUDEPATH += \
    ../
