#ifndef QTLOGGLOBAL_H
#define QTLOGGLOBAL_H

#include <QtCore/QtGlobal>

#if defined(QTLOG_LIBRARY)
#  define QTLOGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTLOGSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif//QTLOGGLOBAL_H
