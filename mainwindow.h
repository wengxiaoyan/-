#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
        //mainwindow是QMainWindow的一个子类
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent*);
    //声明一个函数，这个函数应该是库《QPaintEvent》里的，作用是每次在绘画窗口的时候执行，原理不明
    MainWindow(QWidget *parent = nullptr);
    //构造函数，定义mainwindow对象时执行
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
