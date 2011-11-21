#-------------------------------------------------
#
# Project created by QtCreator 2011-09-22T09:30:39
#
#-------------------------------------------------

QT        = core gui sql
TARGET    = qlogviewer
TEMPLATE  = app

CONFIG   += release

VERSION   = 0.1.0

TEMPLATE += fakelib
TARGET    = $$qtLibraryTarget(qlogviewer)
TEMPLATE -= fakelib

win32 {
   RC_FILE = ../res/qlogviewer.rc
}

DLLDESTDIR  = ../../bin

SOURCES += \
    ../src/querytoolbar.cpp \
    ../src/qdbfileconvertor.cpp \
    ../src/mainwindow.cpp \
    ../src/main.cpp \
    ../src/logitemdelegate.cpp

HEADERS  += \
    ../src/querytoolbar.h \
    ../src/qdbfileconvertor.h \
    ../src/mainwindow.h \
    ../src/logitemdelegate.h

RESOURCES += \
    ../res/qlogviewer.qrc \
    ../res/qlogviewer.qrc

TRANSLATIONS += qlogviewer_zh.ts

MOC_DIR =        ../../tmp
OBJECTS_DIR =    ../../tmp
UI_HEADERS_DIR = ../../tmp
RCC_DIR =        ../../tmp
