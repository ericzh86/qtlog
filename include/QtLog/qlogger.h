#ifndef QLOGGER_H
#define QLOGGER_H

#include "qtlogglobal.h"

class QLoggerKernel;
class QAbstractAppender;

#define QTLOG_LOCALE_SUPPORT

//////////////////////////////////////////////////////////////////////////
// QLogger

#define Q_LOGGER                          \
    protected:                            \
        QLogger *logger()                 \
        {                                 \
            return QLogger::logger(this); \
        }                                 \
    private:

#include <QObject>
class QLoggerPrivate;
class QTLOGSHARED_EXPORT QLogger : public QObject
{
    Q_OBJECT

public:
    QObject *target() const;
public:
    quint32 loggerId() const;

public:
    enum Level
    {
        Off     = 0x00, /*!< Off.   */

        Fatal   = 0x01, /*!< Fatal. */
        Error   = 0x02, /*!< Error. */
        Warn    = 0x04, /*!< Warn.  */
        Info    = 0x08, /*!< Info.  */
        Debug   = 0x10, /*!< Debug. */
        Trace   = 0x20, /*!< Trace. */

        All     = 0xff  /*!< All.   */
    };

public:
    Q_DECLARE_FLAGS(Levels, Level)

public:
    void clearLevels();
public:
    Levels levels() const;
public:
    void setLevels(Levels levels);

public:
    void addAppender(QObject *appender);
public slots:
    void removeAppender(QObject *appender);

public:
    static QLogger *rootLogger();
public:
    static QLogger *logger(QObject *target);

    //////////////////////////////////////////////////////////////////////////
    // 0 Parameter(s)

public:
    void fatal(const QString &text);
    void error(const QString &text);
    void warn(const QString &text);
    void info(const QString &text);
    void debug(const QString &text);
    void trace(const QString &text);

#if defined(QTLOG_LOCALE_SUPPORT)
public:
    void fatal(const char *text);
    void error(const char *text);
    void warn(const char *text);
    void info(const char *text);
    void debug(const char *text);
    void trace(const char *text);
#endif//#if defined(QTLOG_LOCALE_SUPPORT)

    //////////////////////////////////////////////////////////////////////////
    // 1 Parameter(s)

public:
    template <typename P1>
    void fatal(const QString &text, const P1 &p1);
    template <typename P1>
    void error(const QString &text, const P1 &p1);
    template <typename P1>
    void warn(const QString &text, const P1 &p1);
    template <typename P1>
    void info(const QString &text, const P1 &p1);
    template <typename P1>
    void debug(const QString &text, const P1 &p1);
    template <typename P1>
    void trace(const QString &text, const P1 &p1);

#if defined(QTLOG_LOCALE_SUPPORT)
public:
    template <typename P1>
    void fatal(const char *text, const P1 &p1);
    template <typename P1>
    void error(const char *text, const P1 &p1);
    template <typename P1>
    void warn(const char *text, const P1 &p1);
    template <typename P1>
    void info(const char *text, const P1 &p1);
    template <typename P1>
    void debug(const char *text, const P1 &p1);
    template <typename P1>
    void trace(const char *text, const P1 &p1);
#endif//#if defined(QTLOG_LOCALE_SUPPORT)

    //////////////////////////////////////////////////////////////////////////
    // 2 Parameter(s)

public:
    template <typename P1, typename P2>
    void fatal(const QString &text, const P1 &p1, const P2 &p2);
    template <typename P1, typename P2>
    void error(const QString &text, const P1 &p1, const P2 &p2);
    template <typename P1, typename P2>
    void warn(const QString &text, const P1 &p1, const P2 &p2);
    template <typename P1, typename P2>
    void info(const QString &text, const P1 &p1, const P2 &p2);
    template <typename P1, typename P2>
    void debug(const QString &text, const P1 &p1, const P2 &p2);
    template <typename P1, typename P2>
    void trace(const QString &text, const P1 &p1, const P2 &p2);

#if defined(QTLOG_LOCALE_SUPPORT)
public:
    template <typename P1, typename P2>
    void fatal(const char *text, const P1 &p1, const P2 &p2);
    template <typename P1, typename P2>
    void error(const char *text, const P1 &p1, const P2 &p2);
    template <typename P1, typename P2>
    void warn(const char *text, const P1 &p1, const P2 &p2);
    template <typename P1, typename P2>
    void info(const char *text, const P1 &p1, const P2 &p2);
    template <typename P1, typename P2>
    void debug(const char *text, const P1 &p1, const P2 &p2);
    template <typename P1, typename P2>
    void trace(const char *text, const P1 &p1, const P2 &p2);
#endif//#if defined(QTLOG_LOCALE_SUPPORT)

    //////////////////////////////////////////////////////////////////////////
    // 3 Parameter(s)

public:
    template <typename P1, typename P2, typename P3>
    void fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3);
    template <typename P1, typename P2, typename P3>
    void error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3);
    template <typename P1, typename P2, typename P3>
    void warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3);
    template <typename P1, typename P2, typename P3>
    void info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3);
    template <typename P1, typename P2, typename P3>
    void debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3);
    template <typename P1, typename P2, typename P3>
    void trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3);

#if defined(QTLOG_LOCALE_SUPPORT)
public:
    template <typename P1, typename P2, typename P3>
    void fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3);
    template <typename P1, typename P2, typename P3>
    void error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3);
    template <typename P1, typename P2, typename P3>
    void warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3);
    template <typename P1, typename P2, typename P3>
    void info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3);
    template <typename P1, typename P2, typename P3>
    void debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3);
    template <typename P1, typename P2, typename P3>
    void trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3);
#endif//#if defined(QTLOG_LOCALE_SUPPORT)

    //////////////////////////////////////////////////////////////////////////
    // 4 Parameter(s)

public:
    template <typename P1, typename P2, typename P3, typename P4>
    void fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4);
    template <typename P1, typename P2, typename P3, typename P4>
    void error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4);
    template <typename P1, typename P2, typename P3, typename P4>
    void warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4);
    template <typename P1, typename P2, typename P3, typename P4>
    void info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4);
    template <typename P1, typename P2, typename P3, typename P4>
    void debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4);
    template <typename P1, typename P2, typename P3, typename P4>
    void trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4);

#if defined(QTLOG_LOCALE_SUPPORT)
public:
    template <typename P1, typename P2, typename P3, typename P4>
    void fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4);
    template <typename P1, typename P2, typename P3, typename P4>
    void error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4);
    template <typename P1, typename P2, typename P3, typename P4>
    void warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4);
    template <typename P1, typename P2, typename P3, typename P4>
    void info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4);
    template <typename P1, typename P2, typename P3, typename P4>
    void debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4);
    template <typename P1, typename P2, typename P3, typename P4>
    void trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4);
#endif//#if defined(QTLOG_LOCALE_SUPPORT)

    //////////////////////////////////////////////////////////////////////////
    // 5 Parameter(s)

public:
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    void fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5);
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    void error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5);
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    void warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5);
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    void info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5);
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    void debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5);
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    void trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5);

#if defined(QTLOG_LOCALE_SUPPORT)
public:
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    void fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5);
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    void error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5);
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    void warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5);
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    void info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5);
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    void debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5);
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    void trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5);
#endif//#if defined(QTLOG_LOCALE_SUPPORT)

    //////////////////////////////////////////////////////////////////////////
    // 6 Parameter(s)

public:
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    void fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    void error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    void warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    void info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    void debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    void trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6);

#if defined(QTLOG_LOCALE_SUPPORT)
public:
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    void fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    void error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    void warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    void info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    void debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    void trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6);
#endif//#if defined(QTLOG_LOCALE_SUPPORT)

    //////////////////////////////////////////////////////////////////////////
    // 7 Parameter(s)

public:
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    void fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    void error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    void warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    void info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    void debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    void trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7);

#if defined(QTLOG_LOCALE_SUPPORT)
public:
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    void fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    void error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    void warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    void info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    void debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    void trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7);
#endif//#if defined(QTLOG_LOCALE_SUPPORT)

    //////////////////////////////////////////////////////////////////////////
    // 8 Parameter(s)

public:
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
    void fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
    void error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
    void warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
    void info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
    void debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
    void trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8);

#if defined(QTLOG_LOCALE_SUPPORT)
public:
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
    void fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
    void error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
    void warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
    void info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
    void debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
    void trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8);
#endif//#if defined(QTLOG_LOCALE_SUPPORT)

    //////////////////////////////////////////////////////////////////////////
    // 9 Parameter(s)

public:
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
    void fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
    void error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
    void warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
    void info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
    void debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
    void trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9);

#if defined(QTLOG_LOCALE_SUPPORT)
public:
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
    void fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
    void error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
    void warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
    void info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
    void debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9);
    template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
    void trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9);
#endif//#if defined(QTLOG_LOCALE_SUPPORT)

    //////////////////////////////////////////////////////////////////////////
private:
    friend class QLoggerKernel;

private:
    QLogger(QObject *parent, bool isRoot);

private:
    Q_DISABLE_COPY(QLogger)
    Q_DECLARE_PRIVATE(QLogger)

private:
    QList<QAbstractAppender *> _appenders() const;
private:
    void _write(Level level, const QString &text);
};

//////////////////////////////////////////////////////////////////////////
// QLogger

//////////////////////////////////////////////////////////////////////////
// 0 Parameter(s)
inline void QLogger::fatal(const QString &text)
{
    if (text.isEmpty())
            return;

    if (levels() & Fatal)
        _write(Fatal, text);
}

inline void QLogger::error(const QString &text)
{
    if (text.isEmpty())
            return;

    if (levels() & Error)
        _write(Error, text);
}

inline void QLogger::warn(const QString &text)
{
    if (text.isEmpty())
            return;

    if (levels() & Warn)
        _write(Warn, text);
}

inline void QLogger::info(const QString &text)
{
    if (text.isEmpty())
        return;

    if (levels() & Info)
        _write(Info, text);
}

inline void QLogger::debug(const QString &text)
{
	if (text.isEmpty())
		return;

	if (levels() & Debug)
        _write(Debug, text);
}

inline void QLogger::trace(const QString &text)
{
	if (text.isEmpty())
		return;

	if (levels() & Trace)
        _write(Trace, text);
}

#if defined(QTLOG_LOCALE_SUPPORT)

inline void QLogger::fatal(const char *text)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Fatal)
        _write(Fatal, qText);
}

inline void QLogger::error(const char *text)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Error)
        _write(Error, qText);
}

inline void QLogger::warn(const char *text)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Warn)
        _write(Warn, qText);
}

inline void QLogger::info(const char *text)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Info)
        _write(Info, qText);
}

inline void QLogger::debug(const char *text)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Debug)
        _write(Debug, qText);
}

inline void QLogger::trace(const char *text)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

    if (levels() & Trace)
        _write(Trace, qText);
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 1 Parameter(s)

template <typename P1>
inline void QLogger::fatal(const QString &text, const P1 &p1)
{
	if (text.isEmpty())
		return;

	if (levels() & Fatal)
        _write(Fatal, text.arg(p1));
}

template <typename P1>
inline void QLogger::error(const QString &text, const P1 &p1)
{
	if (text.isEmpty())
		return;

	if (levels() & Error)
        _write(Error, text.arg(p1));
}

template <typename P1>
inline void QLogger::warn(const QString &text, const P1 &p1)
{
	if (text.isEmpty())
		return;

	if (levels() & Warn)
        _write(Warn, text.arg(p1));
}

template <typename P1>
inline void QLogger::info(const QString &text, const P1 &p1)
{
	if (text.isEmpty())
		return;

	if (levels() & Info)
        _write(Info, text.arg(p1));
}

template <typename P1>
inline void QLogger::debug(const QString &text, const P1 &p1)
{
	if (text.isEmpty())
		return;

	if (levels() & Debug)
        _write(Debug, text.arg(p1));
}

template <typename P1>
inline void QLogger::trace(const QString &text, const P1 &p1)
{
	if (text.isEmpty())
		return;

	if (levels() & Trace)
        _write(Trace, text.arg(p1));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1>
inline void QLogger::fatal(const char *text, const P1 &p1)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Fatal)
        _write(Fatal, qText.arg(p1));
}

template <typename P1>
inline void QLogger::error(const char *text, const P1 &p1)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Error)
        _write(Error, qText.arg(p1));
}

template <typename P1>
inline void QLogger::warn(const char *text, const P1 &p1)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Warn)
        _write(Warn, qText.arg(p1));
}

template <typename P1>
inline void QLogger::info(const char *text, const P1 &p1)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Info)
        _write(Info, qText.arg(p1));
}

template <typename P1>
inline void QLogger::debug(const char *text, const P1 &p1)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Debug)
        _write(Debug, qText.arg(p1));
}

template <typename P1>
inline void QLogger::trace(const char *text, const P1 &p1)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Trace)
        _write(Trace, qText.arg(p1));
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 2 Parameter(s)

template <typename P1, typename P2>
inline void QLogger::fatal(const QString &text, const P1 &p1, const P2 &p2)
{
	if (text.isEmpty())
		return;

	if (levels() & Fatal)
        _write(Fatal, text.arg(p1).arg(p2));
}

template <typename P1, typename P2>
inline void QLogger::error(const QString &text, const P1 &p1, const P2 &p2)
{
	if (text.isEmpty())
		return;

	if (levels() & Error)
        _write(Error, text.arg(p1).arg(p2));
}

template <typename P1, typename P2>
inline void QLogger::warn(const QString &text, const P1 &p1, const P2 &p2)
{
	if (text.isEmpty())
		return;

	if (levels() & Warn)
        _write(Warn, text.arg(p1).arg(p2));
}

template <typename P1, typename P2>
inline void QLogger::info(const QString &text, const P1 &p1, const P2 &p2)
{
	if (text.isEmpty())
		return;

	if (levels() & Info)
        _write(Info, text.arg(p1).arg(p2));
}

template <typename P1, typename P2>
inline void QLogger::debug(const QString &text, const P1 &p1, const P2 &p2)
{
	if (text.isEmpty())
		return;

	if (levels() & Debug)
        _write(Debug, text.arg(p1).arg(p2));
}

template <typename P1, typename P2>
inline void QLogger::trace(const QString &text, const P1 &p1, const P2 &p2)
{
	if (text.isEmpty())
		return;

	if (levels() & Trace)
        _write(Trace, text.arg(p1).arg(p2));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2>
inline void QLogger::fatal(const char *text, const P1 &p1, const P2 &p2)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Fatal)
        _write(Fatal, qText.arg(p1).arg(p2));
}

template <typename P1, typename P2>
inline void QLogger::error(const char *text, const P1 &p1, const P2 &p2)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Error)
        _write(Error, qText.arg(p1).arg(p2));
}

template <typename P1, typename P2>
inline void QLogger::warn(const char *text, const P1 &p1, const P2 &p2)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Warn)
        _write(Warn, qText.arg(p1).arg(p2));
}

template <typename P1, typename P2>
inline void QLogger::info(const char *text, const P1 &p1, const P2 &p2)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Info)
        _write(Info, qText.arg(p1).arg(p2));
}

template <typename P1, typename P2>
inline void QLogger::debug(const char *text, const P1 &p1, const P2 &p2)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Debug)
        _write(Debug, qText.arg(p1).arg(p2));
}

template <typename P1, typename P2>
inline void QLogger::trace(const char *text, const P1 &p1, const P2 &p2)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Trace)
        _write(Trace, qText.arg(p1).arg(p2));
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 3 Parameter(s)

template <typename P1, typename P2, typename P3>
inline void QLogger::fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3)
{
	if (text.isEmpty())
		return;

	if (levels() & Fatal)
        _write(Fatal, text.arg(p1).arg(p2).arg(p3));
}

template <typename P1, typename P2, typename P3>
inline void QLogger::error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3)
{
	if (text.isEmpty())
		return;

	if (levels() & Error)
        _write(Error, text.arg(p1).arg(p2).arg(p3));
}

template <typename P1, typename P2, typename P3>
inline void QLogger::warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3)
{
	if (text.isEmpty())
		return;

	if (levels() & Warn)
        _write(Warn, text.arg(p1).arg(p2).arg(p3));
}

template <typename P1, typename P2, typename P3>
inline void QLogger::info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3)
{
	if (text.isEmpty())
		return;

	if (levels() & Info)
        _write(Info, text.arg(p1).arg(p2).arg(p3));
}

template <typename P1, typename P2, typename P3>
inline void QLogger::debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3)
{
	if (text.isEmpty())
		return;

	if (levels() & Debug)
        _write(Debug, text.arg(p1).arg(p2).arg(p3));
}

template <typename P1, typename P2, typename P3>
inline void QLogger::trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3)
{
	if (text.isEmpty())
		return;

	if (levels() & Trace)
        _write(Trace, text.arg(p1).arg(p2).arg(p3));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2, typename P3>
inline void QLogger::fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Fatal)
        _write(Fatal, qText.arg(p1).arg(p2).arg(p3));
}

template <typename P1, typename P2, typename P3>
inline void QLogger::error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Error)
        _write(Error, qText.arg(p1).arg(p2).arg(p3));
}

template <typename P1, typename P2, typename P3>
inline void QLogger::warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Warn)
        _write(Warn, qText.arg(p1).arg(p2).arg(p3));
}

template <typename P1, typename P2, typename P3>
inline void QLogger::info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Info)
        _write(Info, qText.arg(p1).arg(p2).arg(p3));
}

template <typename P1, typename P2, typename P3>
inline void QLogger::debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Debug)
        _write(Debug, qText.arg(p1).arg(p2).arg(p3));
}

template <typename P1, typename P2, typename P3>
inline void QLogger::trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
		return;

	if (levels() & Trace)
        _write(Trace, qText.arg(p1).arg(p2).arg(p3));
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 4 Parameter(s)

template <typename P1, typename P2, typename P3, typename P4>
inline void QLogger::fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (text.isEmpty())
        return;

    if (levels() & Fatal)
        _write(Fatal, text.arg(p1).arg(p2).arg(p3).arg(p4));
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QLogger::error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (text.isEmpty())
        return;

    if (levels() & Error)
        _write(Error, text.arg(p1).arg(p2).arg(p3).arg(p4));
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QLogger::warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (text.isEmpty())
        return;

    if (levels() & Warn)
        _write(Warn, text.arg(p1).arg(p2).arg(p3).arg(p4));
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QLogger::info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (text.isEmpty())
        return;

    if (levels() & Info)
        _write(Info, text.arg(p1).arg(p2).arg(p3).arg(p4));
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QLogger::debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (text.isEmpty())
        return;

    if (levels() & Debug)
        _write(Debug, text.arg(p1).arg(p2).arg(p3).arg(p4));
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QLogger::trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (text.isEmpty())
        return;

    if (levels() & Trace)
        _write(Trace, text.arg(p1).arg(p2).arg(p3).arg(p4));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2, typename P3, typename P4>
inline void QLogger::fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Fatal)
        _write(Fatal, qText.arg(p1).arg(p2).arg(p3).arg(p4));
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QLogger::error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Error)
        _write(Error, qText.arg(p1).arg(p2).arg(p3).arg(p4));
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QLogger::warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Warn)
        _write(Warn, qText.arg(p1).arg(p2).arg(p3).arg(p4));
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QLogger::info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Info)
        _write(Info, qText.arg(p1).arg(p2).arg(p3).arg(p4));
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QLogger::debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Debug)
        _write(Debug, qText.arg(p1).arg(p2).arg(p3).arg(p4));
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QLogger::trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Trace)
        _write(Trace, qText.arg(p1).arg(p2).arg(p3).arg(p4));
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 5 Parameter(s)

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QLogger::fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (text.isEmpty())
        return;

    if (levels() & Fatal)
        _write(Fatal, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QLogger::error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (text.isEmpty())
        return;

    if (levels() & Error)
        _write(Error, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QLogger::warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (text.isEmpty())
        return;

    if (levels() & Warn)
        _write(Warn, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QLogger::info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (text.isEmpty())
        return;

    if (levels() & Info)
        _write(Info, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QLogger::debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (text.isEmpty())
        return;

    if (levels() & Debug)
        _write(Debug, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QLogger::trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (text.isEmpty())
        return;

    if (levels() & Trace)
        _write(Trace, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QLogger::fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Fatal)
        _write(Fatal, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QLogger::error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Error)
        _write(Error, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QLogger::warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Warn)
        _write(Warn, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QLogger::info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Info)
        _write(Info, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QLogger::debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Debug)
        _write(Debug, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QLogger::trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Trace)
        _write(Trace, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 6 Parameter(s)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QLogger::fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (text.isEmpty())
        return;

    if (levels() & Fatal)
        _write(Fatal, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QLogger::error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (text.isEmpty())
        return;

    if (levels() & Error)
        _write(Error, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QLogger::warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (text.isEmpty())
        return;

    if (levels() & Warn)
        _write(Warn, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QLogger::info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (text.isEmpty())
        return;

    if (levels() & Info)
        _write(Info, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QLogger::debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (text.isEmpty())
        return;

    if (levels() & Debug)
        _write(Debug, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QLogger::trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (text.isEmpty())
        return;

    if (levels() & Trace)
        _write(Trace, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QLogger::fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Fatal)
        _write(Fatal, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QLogger::error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Error)
        _write(Error, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QLogger::warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Warn)
        _write(Warn, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QLogger::info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Info)
        _write(Info, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QLogger::debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Debug)
        _write(Debug, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QLogger::trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Trace)
        _write(Trace, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 7 Parameter(s)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QLogger::fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (text.isEmpty())
        return;

    if (levels() & Fatal)
        _write(Fatal, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QLogger::error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (text.isEmpty())
        return;

    if (levels() & Error)
        _write(Error, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QLogger::warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (text.isEmpty())
        return;

    if (levels() & Warn)
        _write(Warn, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QLogger::info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (text.isEmpty())
        return;

    if (levels() & Info)
        _write(Info, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QLogger::debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (text.isEmpty())
        return;

    if (levels() & Debug)
        _write(Debug, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QLogger::trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (text.isEmpty())
        return;

    if (levels() & Trace)
        _write(Trace, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QLogger::fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Fatal)
        _write(Fatal, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QLogger::error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Error)
        _write(Error, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QLogger::warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Warn)
        _write(Warn, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QLogger::info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Info)
        _write(Info, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QLogger::debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Debug)
        _write(Debug, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QLogger::trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Trace)
        _write(Trace, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 8 Parameter(s)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QLogger::fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (text.isEmpty())
        return;

    if (levels() & Fatal)
        _write(Fatal, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QLogger::error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (text.isEmpty())
        return;

    if (levels() & Error)
        _write(Error, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QLogger::warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (text.isEmpty())
        return;

    if (levels() & Warn)
        _write(Warn, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QLogger::info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (text.isEmpty())
        return;

    if (levels() & Info)
        _write(Info, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QLogger::debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (text.isEmpty())
        return;

    if (levels() & Debug)
        _write(Debug, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QLogger::trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (text.isEmpty())
        return;

    if (levels() & Trace)
        _write(Trace, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QLogger::fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Fatal)
        _write(Fatal, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QLogger::error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Error)
        _write(Error, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QLogger::warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Warn)
        _write(Warn, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QLogger::info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Info)
        _write(Info, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QLogger::debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Debug)
        _write(Debug, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QLogger::trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Trace)
        _write(Trace, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 9 Parameter(s)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QLogger::fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (text.isEmpty())
        return;

    if (levels() & Fatal)
        _write(Fatal, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QLogger::error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (text.isEmpty())
        return;

    if (levels() & Error)
        _write(Error, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QLogger::warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (text.isEmpty())
        return;

    if (levels() & Warn)
        _write(Warn, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QLogger::info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (text.isEmpty())
        return;

    if (levels() & Info)
        _write(Info, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QLogger::debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (text.isEmpty())
        return;

    if (levels() & Debug)
        _write(Debug, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QLogger::trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (text.isEmpty())
        return;

    if (levels() & Trace)
        _write(Trace, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QLogger::fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Fatal)
        _write(Fatal, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QLogger::error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Error)
        _write(Error, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QLogger::warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Warn)
        _write(Warn, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QLogger::info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Info)
        _write(Info, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QLogger::debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Debug)
        _write(Debug, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QLogger::trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    QString qText = QString::fromLocal8Bit(text);

    if (qText.isEmpty())
        return;

    if (levels() & Trace)
        _write(Trace, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

#endif//QLOGGER_H
