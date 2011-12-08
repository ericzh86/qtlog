QT      += core gui
TEMPLATE = app

TEMPLATE += fakelib
TARGET    = $$qtLibraryTarget(qlogdemo)
TEMPLATE -= fakelib

DESTDIR  = $$PWD/../bin

Debug: LIBS += -lQtLogd0
Release: LIBS += -lQtLog0

SOURCES += main.cpp \
           mainwindow.cpp

HEADERS += mainwindow.h

FORMS   +=
