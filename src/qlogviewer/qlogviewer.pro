QT       += core gui sql

TEMPLATE  = app

VERSION   = 0.1.0

TEMPLATE += fakelib
TARGET    = $$qtLibraryTarget(qlogviewer)
TEMPLATE -= fakelib

win32 {
    DLLDESTDIR = $$[QT_INSTALL_BINS]
}

include(qlogviewer.pri)
