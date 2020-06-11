#include "mywindow.h"
#include "mybutton.h"
#include <QTimer>
#include <QPaintEvent>
#include <QPainter>

MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent)
{
//设置MyWindow的构造函数，这是继承于QMainWindow的，用parent将QMianWindow初始化
    this->setFixedSize(800,600);
    //设置窗口2大小
    MyButton* back_btn = new MyButton(":/6");
    //创建一个返回按钮
    back_btn->setParent(this);
    //确定返回按钮在哪个窗口出现
    back_btn->move(0,0);
    //返回按钮位置
    MyButton* setTower = new MyButton(":/7");
    //建塔按钮
    setTower->setParent(this);
    //建塔按钮出现窗口
    setTower->move(50,100);
    //建塔按钮出现位置
    connect(setTower,&MyButton::clicked,this,&MyWindow::set_tower);
    //把建塔建和建塔连接
    connect(back_btn,&MyButton::clicked,this,[=](){
        back_btn->zoomdown();
        back_btn->zoomup();
        QTimer::singleShot(400,this,[=](){
            emit chooseBack();
        });
    });
    //连接返回键与信号发射功能
}

void MyWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    //在scene上画图
    QPixmap pixmap(":/3");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
    //调用painter的成员函数实现绘图
    foreach(Tower* tower, tower_list)//遍历list，将tower_list的所有成员一次赋给tower
        tower->draw(&painter);
    //绘制
}

void MyWindow::set_tower()
{
    Tower* a_new_tower = new Tower(QPoint(100,70),":/4");
    tower_list.push_back(a_new_tower);
    update();//重新绘制窗口
}
