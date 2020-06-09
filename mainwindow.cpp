#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mybutton.h"
#include "mywindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyButton* btn = new MyButton(":/1");
    btn->setParent(this);
    btn->move(325,450);
    MyWindow* scene = new MyWindow;
    connect(btn,&MyButton::clicked,this,[=](){
        btn->zoomdown();
        btn->zoomup();
        QTimer::singleShot(400,this,[=](){
            this->hide();
            scene->show();
        });
    });
    connect(scene,&MyWindow::chooseBack,this,[=](){
        scene->hide();
        this->show();
    });
    this->setFixedSize(800,600);//确定主界面大小
    //QPushButton* btn = new QPushButton(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);//在主界面上画图
    QPixmap pixmap(":/2");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
