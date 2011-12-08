#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "../../include/QtLog/QtLog"
// 如果安装到Qt的SDK目录, 可以按照下面的写法
// #include <QtLog/QtLog>

class MainWindow : public QWidget
{
    Q_OBJECT
    // 这里定义日志宏
    Q_LOGGER

public:
    MainWindow();
};

#endif//MAINWINDOW_H
