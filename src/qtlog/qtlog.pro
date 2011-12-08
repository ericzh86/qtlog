QT       += core
QT       -= gui

TEMPLATE  = lib

VERSION   = 0.5.0

TEMPLATE += fakelib
TARGET    = $$qtLibraryTarget(QtLog)
TEMPLATE -= fakelib

DEFINES  += QTLOG_LIBRARY

win32 {
    DESTDIR    = $$[QT_INSTALL_LIBS]
    DLLDESTDIR = $$[QT_INSTALL_BINS]
}

include(qtlog.pri)
