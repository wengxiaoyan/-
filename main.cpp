#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //定义了一个mainwindow对象
    w.show();
    //创建mainwindow窗口
    return a.exec();
}
