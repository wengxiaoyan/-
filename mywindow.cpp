#include "mywindow.h"
#include "mybutton.h"
#include <QTimer>
#include <QPaintEvent>
#include <QPainter>

MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(800,600);
    MyButton* back_btn = new MyButton(":/6");
    back_btn->setParent(this);
    back_btn->move(0,0);
    connect(back_btn,&MyButton::clicked,this,[=](){
        back_btn->zoomdown();
        back_btn->zoomup();
        QTimer::singleShot(400,this,[=](){
            emit chooseBack();
        });
    });
}

void MyWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);//在scene上画图
    QPixmap pixmap(":/3");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
