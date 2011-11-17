#-------------------------------------------------
#
# Project created by QtCreator 2011-09-20T15:12:11
#
#-------------------------------------------------

QT        = core
CONFIG   += build_all
TEMPLATE  = lib

VERSION   = 0.5.0

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
    ../src/qtextfileappender.h \
    ../src/qsqliteappender.h \
    ../src/qsimpleformatter.h \
    ../src/qrootloggerfactory.h \
    ../src/qrootlogger.h \
    ../src/qobjectloggerfactory.h \
    ../src/qobjectlogger.h \
    ../src/qconsoleappender.h \
    ../src/qabstractlogger.h \
    ../src/qabstractformatter.h \
    ../src/qabstractappender.h \
    ../src/private/qobject_p.h \
    ../src/private/qabstractlogger_p.h \
    ../src/private/qabstractformatter_p.h \
    ../src/private/qabstractappender_p.h

SOURCES += \
    ../src/qtextfileappender.cpp \
    ../src/qsqliteappender.cpp \
    ../src/qsimpleformatter.cpp \
    ../src/qrootloggerfactory.cpp \
    ../src/qrootlogger.cpp \
    ../src/qobjectloggerfactory.cpp \
    ../src/qobjectlogger.cpp \
    ../src/qconsoleappender.cpp \
    ../src/qabstractlogger.cpp \
    ../src/qabstractformatter.cpp \
    ../src/qabstractappender.cpp \
    ../src/main.cpp \
    ../src/private/qabstractlogger_p.cpp \
    ../src/private/qabstractformatter_p.cpp \
    ../src/private/qabstractappender_p.cpp
