#include "mybutton.h"
#include <QPixmap>
#include <QPropertyAnimation>
MyButton::MyButton(QString pix):QPushButton(0){
//现在定义MyButton的构造函数，这个类继承于QPushButton，QPushButton是一个可以用0初始化的类，虽然不知到用0初始化是什么意思
    QPixmap pixmap(pix);
    this->setFixedSize(pixmap.width(),pixmap.height());
    //设置按钮的大小（有可能从按钮中截取一半）
    this->setStyleSheet("QPushButton{border:Opx;}");
    //这一行可以使按钮变成图片的形状，原理未知
    this->setIcon(pixmap);
    //设置按钮要变成什么图片
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    //设置图片的大小，一次来控制按钮大小
}

void MyButton::zoomdown(){
    QPropertyAnimation* animation = new QPropertyAnimation(this,"geometry");
    //创建了一个QPropertyAnimation类的对象，这个类用于管理动画效果，这个对象用于改变MyButton的geometry性质（位置）
    animation->setDuration(200);
    //设置动画持续时间
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置从哪开始动
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置动到哪里为止
    animation->setEasingCurve(QEasingCurve::OutBack);
    //设置运动模式
    animation->start();
    //开始运动
}

void MyButton::zoomup(){
    QPropertyAnimation* animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBack);
    animation->start();
    //同上
}
