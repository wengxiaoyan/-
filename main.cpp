#include "mainwindow.h"
#include "mywindow.h"
#include <QApplication>    //新加
#include <QtMultimedia/QMediaPlayer> //新加
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //定义了一个mainwindow对象
    w.show();
    return a.exec();
}
