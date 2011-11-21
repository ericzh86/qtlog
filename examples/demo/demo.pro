#-------------------------------------------------
#
# Project created by QtCreator 2011-10-10T16:41:45
#
#-------------------------------------------------

QT      += core gui
TARGET   = demo
TEMPLATE = app

DESTDIR  = ../../bin

LIBS    += -l../../lib/QtLogd0

SOURCES += main.cpp \
           mainwindow.cpp

HEADERS += mainwindow.h

FORMS   += mainwindow.ui

MOC_DIR =        ../../tmp
OBJECTS_DIR =    ../../tmp
UI_HEADERS_DIR = ../../tmp
