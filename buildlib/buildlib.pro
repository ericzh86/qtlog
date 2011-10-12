#-------------------------------------------------
#
# Project created by QtCreator 2011-09-20T15:12:11
#
#-------------------------------------------------

QT        = core
CONFIG   += build_all
TEMPLATE  = lib

VERSION   = 0.3.5

TEMPLATE += fakelib
TARGET    = $$qtLibraryTarget(QtLog)
TEMPLATE -= fakelib

DEFINES += QTLOG_LIBRARY

win32 {
    DESTDIR    = ../lib
    DLLDESTDIR = ../bin
}

HEADERS += \
    ../src/qtlogglobal.h \
    ../src/qlogger_p.h \
    ../src/qlogger.h \
    ../src/qabstractappender.h \
    ../src/qdbfileappender.h \
    ../src/qconsoleappender.h \
    ../src/qtextfileappender.h

SOURCES += \
    ../src/qlogger_p.cpp \
    ../src/qlogger.cpp \
    ../src/qabstractappender.cpp \
    ../src/qdbfileappender.cpp \
    ../src/qconsoleappender.cpp \
    ../src/qtextfileappender.cpp
