#ifndef QABSTRACTLOGGER_H
#define QABSTRACTLOGGER_H

#include "qtlogglobal.h"

#include <QObject>
class QAbstractLoggerPrivate;
class QTLOGSHARED_EXPORT QAbstractLogger : public QObject
{
    Q_OBJECT

    // Constructors
protected:
    explicit QAbstractLogger(QObject *target, QObject *parent = 0);
protected:
    explicit QAbstractLogger(QAbstractLoggerPrivate &dd, QObject *target, QObject *parent = 0);

    // Target
public:
    QObject *target() const;

    // LoggerId
public:
    quint32 loggerId() const;

    // Levels
public:
    virtual void setLevels(QLogLevels newLevels);
public:
    virtual QLogLevels levels() const;

public:
    bool isFatalEnabled() const;
public:
    bool isErrorEnabled() const;
public:
    bool isWarnEnabled() const;
public:
    bool isInfoEnabled() const;
public:
    bool isDebugEnabled() const;
public:
    bool isTraceEnabled() const;

    // Appenders
public:
    void addAppender(QAbstractAppender *appender);
public:
    void removeAppender(QAbstractAppender *appender);
public:
    const QList<QAbstractAppender *> &appenders() const;

private slots:
    void _q_removeAppender(QObject *appender);

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
    friend class QRootLogger;
    friend class QClassLogger;
    friend class QObjectLogger;

private:
    Q_DISABLE_COPY(QAbstractLogger)
    Q_DECLARE_PRIVATE(QAbstractLogger)

protected:
    virtual void write(QAbstractLogger *logger, QLogLevel level, const QString &text);
};

//////////////////////////////////////////////////////////////////////////
// QAbstractLogger Inline Functions

inline bool QAbstractLogger::isFatalEnabled() const
{
    return (levels() & QtLog::Fatal);
}

inline bool QAbstractLogger::isErrorEnabled() const
{
    return (levels() & QtLog::Error);
}

inline bool QAbstractLogger::isWarnEnabled() const
{
    return (levels() & QtLog::Warn);
}

inline bool QAbstractLogger::isInfoEnabled() const
{
    return (levels() & QtLog::Info);
}

inline bool QAbstractLogger::isDebugEnabled() const
{
    return (levels() & QtLog::Debug);
}

inline bool QAbstractLogger::isTraceEnabled() const
{
    return (levels() & QtLog::Trace);
}

//////////////////////////////////////////////////////////////////////////
// 0 Parameter(s)
inline void QAbstractLogger::fatal(const QString &text)
{
    if (isFatalEnabled() && !text.isEmpty())
        write(this, QtLog::Fatal, text);
}

inline void QAbstractLogger::error(const QString &text)
{
    if (isErrorEnabled() && !text.isEmpty())
        write(this, QtLog::Error, text);
}

inline void QAbstractLogger::warn(const QString &text)
{
    if (isWarnEnabled() && !text.isEmpty())
        write(this, QtLog::Warn, text);
}

inline void QAbstractLogger::info(const QString &text)
{
    if (isInfoEnabled() && !text.isEmpty())
        write(this, QtLog::Info, text);
}

inline void QAbstractLogger::debug(const QString &text)
{
    if (isDebugEnabled() && !text.isEmpty())
        write(this, QtLog::Debug, text);
}

inline void QAbstractLogger::trace(const QString &text)
{
    if (isTraceEnabled() && !text.isEmpty())
        write(this, QtLog::Trace, text);
}

#if defined(QTLOG_LOCALE_SUPPORT)

inline void QAbstractLogger::fatal(const char *text)
{
    if (isFatalEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Fatal, qText);
        }
    }
}

inline void QAbstractLogger::error(const char *text)
{
    if (isErrorEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Error, qText);
        }
    }
}

inline void QAbstractLogger::warn(const char *text)
{
    if (isWarnEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Warn, qText);
        }
    }
}

inline void QAbstractLogger::info(const char *text)
{
    if (isInfoEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Info, qText);
        }
    }
}

inline void QAbstractLogger::debug(const char *text)
{
    if (isDebugEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Debug, qText);
        }
    }
}

inline void QAbstractLogger::trace(const char *text)
{
    if (isTraceEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Trace, qText);
        }
    }
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 1 Parameter(s)

template <typename P1>
inline void QAbstractLogger::fatal(const QString &text, const P1 &p1)
{
    if (isFatalEnabled() && !text.isEmpty())
        write(this, QtLog::Fatal, text.arg(p1));
}

template <typename P1>
inline void QAbstractLogger::error(const QString &text, const P1 &p1)
{
    if (isErrorEnabled() && !text.isEmpty())
        write(this, QtLog::Error, text.arg(p1));
}

template <typename P1>
inline void QAbstractLogger::warn(const QString &text, const P1 &p1)
{
    if (isWarnEnabled() && !text.isEmpty())
        write(this, QtLog::Warn, text.arg(p1));
}

template <typename P1>
inline void QAbstractLogger::info(const QString &text, const P1 &p1)
{
    if (isInfoEnabled() && !text.isEmpty())
        write(this, QtLog::Info, text.arg(p1));
}

template <typename P1>
inline void QAbstractLogger::debug(const QString &text, const P1 &p1)
{
    if (isDebugEnabled() && !text.isEmpty())
        write(this, QtLog::Debug, text.arg(p1));
}

template <typename P1>
inline void QAbstractLogger::trace(const QString &text, const P1 &p1)
{
    if (isTraceEnabled() && !text.isEmpty())
        write(this, QtLog::Trace, text.arg(p1));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1>
inline void QAbstractLogger::fatal(const char *text, const P1 &p1)
{
    if (isFatalEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Fatal, qText.arg(p1));
        }
    }
}

template <typename P1>
inline void QAbstractLogger::error(const char *text, const P1 &p1)
{
    if (isErrorEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Error, qText.arg(p1));
        }
    }
}

template <typename P1>
inline void QAbstractLogger::warn(const char *text, const P1 &p1)
{
    if (isWarnEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Warn, qText.arg(p1));
        }
    }
}

template <typename P1>
inline void QAbstractLogger::info(const char *text, const P1 &p1)
{
    if (isInfoEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Info, qText.arg(p1));
        }
    }
}

template <typename P1>
inline void QAbstractLogger::debug(const char *text, const P1 &p1)
{
    if (isDebugEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Debug, qText.arg(p1));
        }
    }
}

template <typename P1>
inline void QAbstractLogger::trace(const char *text, const P1 &p1)
{
    if (isTraceEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Trace, qText.arg(p1));
        }
    }
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 2 Parameter(s)

template <typename P1, typename P2>
inline void QAbstractLogger::fatal(const QString &text, const P1 &p1, const P2 &p2)
{
    if (isFatalEnabled() && !text.isEmpty())
        write(this, QtLog::Fatal, text.arg(p1).arg(p2));
}

template <typename P1, typename P2>
inline void QAbstractLogger::error(const QString &text, const P1 &p1, const P2 &p2)
{
    if (isErrorEnabled() && !text.isEmpty())
        write(this, QtLog::Error, text.arg(p1).arg(p2));
}

template <typename P1, typename P2>
inline void QAbstractLogger::warn(const QString &text, const P1 &p1, const P2 &p2)
{
    if (isWarnEnabled() && !text.isEmpty())
        write(this, QtLog::Warn, text.arg(p1).arg(p2));
}

template <typename P1, typename P2>
inline void QAbstractLogger::info(const QString &text, const P1 &p1, const P2 &p2)
{
    if (isInfoEnabled() && !text.isEmpty())
        write(this, QtLog::Info, text.arg(p1).arg(p2));
}

template <typename P1, typename P2>
inline void QAbstractLogger::debug(const QString &text, const P1 &p1, const P2 &p2)
{
    if (isDebugEnabled() && !text.isEmpty())
        write(this, QtLog::Debug, text.arg(p1).arg(p2));
}

template <typename P1, typename P2>
inline void QAbstractLogger::trace(const QString &text, const P1 &p1, const P2 &p2)
{
    if (isTraceEnabled() && !text.isEmpty())
        write(this, QtLog::Trace, text.arg(p1).arg(p2));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2>
inline void QAbstractLogger::fatal(const char *text, const P1 &p1, const P2 &p2)
{
    if (isFatalEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Fatal, qText.arg(p1).arg(p2));
        }
    }
}

template <typename P1, typename P2>
inline void QAbstractLogger::error(const char *text, const P1 &p1, const P2 &p2)
{
    if (isErrorEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Error, qText.arg(p1).arg(p2));
        }
    }
}

template <typename P1, typename P2>
inline void QAbstractLogger::warn(const char *text, const P1 &p1, const P2 &p2)
{
    if (isWarnEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Warn, qText.arg(p1).arg(p2));
        }
    }
}

template <typename P1, typename P2>
inline void QAbstractLogger::info(const char *text, const P1 &p1, const P2 &p2)
{
    if (isInfoEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Info, qText.arg(p1).arg(p2));
        }
    }
}

template <typename P1, typename P2>
inline void QAbstractLogger::debug(const char *text, const P1 &p1, const P2 &p2)
{
    if (isDebugEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Debug, qText.arg(p1).arg(p2));
        }
    }
}

template <typename P1, typename P2>
inline void QAbstractLogger::trace(const char *text, const P1 &p1, const P2 &p2)
{
    if (isTraceEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Trace, qText.arg(p1).arg(p2));
        }
    }
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 3 Parameter(s)

template <typename P1, typename P2, typename P3>
inline void QAbstractLogger::fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    if (isFatalEnabled() && !text.isEmpty())
        write(this, QtLog::Fatal, text.arg(p1).arg(p2).arg(p3));
}

template <typename P1, typename P2, typename P3>
inline void QAbstractLogger::error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    if (isErrorEnabled() && !text.isEmpty())
        write(this, QtLog::Error, text.arg(p1).arg(p2).arg(p3));
}

template <typename P1, typename P2, typename P3>
inline void QAbstractLogger::warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    if (isWarnEnabled() && !text.isEmpty())
        write(this, QtLog::Warn, text.arg(p1).arg(p2).arg(p3));
}

template <typename P1, typename P2, typename P3>
inline void QAbstractLogger::info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    if (isInfoEnabled() && !text.isEmpty())
        write(this, QtLog::Info, text.arg(p1).arg(p2).arg(p3));
}

template <typename P1, typename P2, typename P3>
inline void QAbstractLogger::debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    if (isDebugEnabled() && !text.isEmpty())
        write(this, QtLog::Debug, text.arg(p1).arg(p2).arg(p3));
}

template <typename P1, typename P2, typename P3>
inline void QAbstractLogger::trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    if (isTraceEnabled() && !text.isEmpty())
        write(this, QtLog::Trace, text.arg(p1).arg(p2).arg(p3));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2, typename P3>
inline void QAbstractLogger::fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    if (isFatalEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Fatal, qText.arg(p1).arg(p2).arg(p3));
        }
    }
}

template <typename P1, typename P2, typename P3>
inline void QAbstractLogger::error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    if (isErrorEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Error, qText.arg(p1).arg(p2).arg(p3));
        }
    }
}

template <typename P1, typename P2, typename P3>
inline void QAbstractLogger::warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    if (isWarnEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Warn, qText.arg(p1).arg(p2).arg(p3));
        }
    }
}

template <typename P1, typename P2, typename P3>
inline void QAbstractLogger::info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    if (isInfoEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Info, qText.arg(p1).arg(p2).arg(p3));
        }
    }
}

template <typename P1, typename P2, typename P3>
inline void QAbstractLogger::debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    if (isDebugEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Debug, qText.arg(p1).arg(p2).arg(p3));
        }
    }
}

template <typename P1, typename P2, typename P3>
inline void QAbstractLogger::trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3)
{
    if (isTraceEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Trace, qText.arg(p1).arg(p2).arg(p3));
        }
    }
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 4 Parameter(s)

template <typename P1, typename P2, typename P3, typename P4>
inline void QAbstractLogger::fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (isFatalEnabled() && !text.isEmpty())
        write(this, QtLog::Fatal, text.arg(p1).arg(p2).arg(p3).arg(p4));
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QAbstractLogger::error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (isErrorEnabled() && !text.isEmpty())
        write(this, QtLog::Error, text.arg(p1).arg(p2).arg(p3).arg(p4));
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QAbstractLogger::warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (isWarnEnabled() && !text.isEmpty())
        write(this, QtLog::Warn, text.arg(p1).arg(p2).arg(p3).arg(p4));
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QAbstractLogger::info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (isInfoEnabled() && !text.isEmpty())
        write(this, QtLog::Info, text.arg(p1).arg(p2).arg(p3).arg(p4));
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QAbstractLogger::debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (isDebugEnabled() && !text.isEmpty())
        write(this, QtLog::Debug, text.arg(p1).arg(p2).arg(p3).arg(p4));
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QAbstractLogger::trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (isTraceEnabled() && !text.isEmpty())
        write(this, QtLog::Trace, text.arg(p1).arg(p2).arg(p3).arg(p4));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2, typename P3, typename P4>
inline void QAbstractLogger::fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (isFatalEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Fatal, qText.arg(p1).arg(p2).arg(p3).arg(p4));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QAbstractLogger::error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (isErrorEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Error, qText.arg(p1).arg(p2).arg(p3).arg(p4));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QAbstractLogger::warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (isWarnEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Warn, qText.arg(p1).arg(p2).arg(p3).arg(p4));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QAbstractLogger::info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (isInfoEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Info, qText.arg(p1).arg(p2).arg(p3).arg(p4));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QAbstractLogger::debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (isDebugEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Debug, qText.arg(p1).arg(p2).arg(p3).arg(p4));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4>
inline void QAbstractLogger::trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
{
    if (isTraceEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Trace, qText.arg(p1).arg(p2).arg(p3).arg(p4));
        }
    }
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 5 Parameter(s)

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QAbstractLogger::fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (isFatalEnabled() && !text.isEmpty())
        write(this, QtLog::Fatal, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QAbstractLogger::error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (isErrorEnabled() && !text.isEmpty())
        write(this, QtLog::Error, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QAbstractLogger::warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (isWarnEnabled() && !text.isEmpty())
        write(this, QtLog::Warn, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QAbstractLogger::info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (isInfoEnabled() && !text.isEmpty())
        write(this, QtLog::Info, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QAbstractLogger::debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (isDebugEnabled() && !text.isEmpty())
        write(this, QtLog::Debug, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QAbstractLogger::trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (isTraceEnabled() && !text.isEmpty())
        write(this, QtLog::Trace, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QAbstractLogger::fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (isFatalEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Fatal, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QAbstractLogger::error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (isErrorEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Error, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QAbstractLogger::warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (isWarnEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Warn, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QAbstractLogger::info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (isInfoEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Info, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QAbstractLogger::debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (isDebugEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Debug, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
inline void QAbstractLogger::trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
{
    if (isTraceEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Trace, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5));
        }
    }
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 6 Parameter(s)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QAbstractLogger::fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (isFatalEnabled() && !text.isEmpty())
        write(this, QtLog::Fatal, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QAbstractLogger::error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (isErrorEnabled() && !text.isEmpty())
        write(this, QtLog::Error, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QAbstractLogger::warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (isWarnEnabled() && !text.isEmpty())
        write(this, QtLog::Warn, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QAbstractLogger::info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (isInfoEnabled() && !text.isEmpty())
        write(this, QtLog::Info, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QAbstractLogger::debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (isDebugEnabled() && !text.isEmpty())
        write(this, QtLog::Debug, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QAbstractLogger::trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (isTraceEnabled() && !text.isEmpty())
        write(this, QtLog::Trace, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QAbstractLogger::fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (isFatalEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Fatal, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QAbstractLogger::error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (isErrorEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Error, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QAbstractLogger::warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (isWarnEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Warn, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QAbstractLogger::info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (isInfoEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Info, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QAbstractLogger::debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (isDebugEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Debug, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
inline void QAbstractLogger::trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
{
    if (isTraceEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Trace, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6));
        }
    }
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 7 Parameter(s)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QAbstractLogger::fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (isFatalEnabled() && !text.isEmpty())
        write(this, QtLog::Fatal, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QAbstractLogger::error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (isErrorEnabled() && !text.isEmpty())
        write(this, QtLog::Error, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QAbstractLogger::warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (isWarnEnabled() && !text.isEmpty())
        write(this, QtLog::Warn, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QAbstractLogger::info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (isInfoEnabled() && !text.isEmpty())
        write(this, QtLog::Info, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QAbstractLogger::debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (isDebugEnabled() && !text.isEmpty())
        write(this, QtLog::Debug, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QAbstractLogger::trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (isTraceEnabled() && !text.isEmpty())
        write(this, QtLog::Trace, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QAbstractLogger::fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (isFatalEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Fatal, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QAbstractLogger::error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (isErrorEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Error, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QAbstractLogger::warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (isWarnEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Warn, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QAbstractLogger::info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (isInfoEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Info, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QAbstractLogger::debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (isDebugEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Debug, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
inline void QAbstractLogger::trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
{
    if (isTraceEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Trace, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7));
        }
    }
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 8 Parameter(s)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QAbstractLogger::fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (isFatalEnabled() && !text.isEmpty())
        write(this, QtLog::Fatal, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QAbstractLogger::error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (isErrorEnabled() && !text.isEmpty())
        write(this, QtLog::Error, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QAbstractLogger::warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (isWarnEnabled() && !text.isEmpty())
        write(this, QtLog::Warn, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QAbstractLogger::info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (isInfoEnabled() && !text.isEmpty())
        write(this, QtLog::Info, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QAbstractLogger::debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (isDebugEnabled() && !text.isEmpty())
        write(this, QtLog::Debug, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QAbstractLogger::trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (isTraceEnabled() && !text.isEmpty())
        write(this, QtLog::Trace, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QAbstractLogger::fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (isFatalEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Fatal, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QAbstractLogger::error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (isErrorEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Error, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QAbstractLogger::warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (isWarnEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Warn, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QAbstractLogger::info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (isInfoEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Info, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QAbstractLogger::debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (isDebugEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Debug, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
inline void QAbstractLogger::trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
{
    if (isTraceEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Trace, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8));
        }
    }
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

//////////////////////////////////////////////////////////////////////////
// 9 Parameter(s)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QAbstractLogger::fatal(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (isFatalEnabled() && !text.isEmpty())
        write(this, QtLog::Fatal, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QAbstractLogger::error(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (isErrorEnabled() && !text.isEmpty())
        write(this, QtLog::Error, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QAbstractLogger::warn(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (isWarnEnabled() && !text.isEmpty())
        write(this, QtLog::Warn, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QAbstractLogger::info(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (isInfoEnabled() && !text.isEmpty())
        write(this, QtLog::Info, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QAbstractLogger::debug(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (isDebugEnabled() && !text.isEmpty())
        write(this, QtLog::Debug, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QAbstractLogger::trace(const QString &text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (isTraceEnabled() && !text.isEmpty())
        write(this, QtLog::Trace, text.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
}

#if defined(QTLOG_LOCALE_SUPPORT)

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QAbstractLogger::fatal(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (isFatalEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Fatal, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QAbstractLogger::error(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (isErrorEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Error, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QAbstractLogger::warn(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (isWarnEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Warn, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QAbstractLogger::info(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (isInfoEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Info, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QAbstractLogger::debug(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (isDebugEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Debug, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
        }
    }
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
inline void QAbstractLogger::trace(const char *text, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
{
    if (isTraceEnabled()) {
        QString qText = QString::fromLocal8Bit(text);
        if (!qText.isEmpty()) {
            write(this, QtLog::Trace, qText.arg(p1).arg(p2).arg(p3).arg(p4).arg(p5).arg(p6).arg(p7).arg(p8).arg(p9));
        }
    }
}

#endif//#if defined(QTLOG_LOCALE_SUPPORT)

#endif//QABSTRACTLOGGER_H
