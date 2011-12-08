#ifndef QTLOGGLOBAL_H
#define QTLOGGLOBAL_H

#include <QtCore/QtGlobal>

#if defined(QTLOG_LIBRARY)
#  define QTLOGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTLOGSHARED_EXPORT Q_DECL_IMPORT
#endif

namespace QtLog
{
    enum Level
    {
        Off    = 0x00,

        Fatal  = 0x01,
        Error  = 0x02,
        Warn   = 0x04,
        Info   = 0x08,
        Debug  = 0x10,
        Trace  = 0x20,

        All    = 0xff
    };

    enum Format
    {
        ClassName   = 0x01,
        Date        = 0x02,
        Time        = 0x04,

        AllFormats  = 0xff
    };
}

typedef QtLog::Level QLogLevel;
typedef QtLog::Format QLogFormat;

Q_DECLARE_FLAGS(QLogLevels, QLogLevel)
Q_DECLARE_FLAGS(QLogFormats, QLogFormat)

class QAbstractLogger;

class QAbstractAppender;
class QAbstractFormatter;

class QRootLogger;
class QClassLogger;
class QObjectLogger;

class QSQLiteAppender;
class QConsoleAppender;
class QTextFileAppender;

class QSimpleFormatter;

#define QTLOG_LOCALE_SUPPORT

#endif//QTLOGGLOBAL_H
