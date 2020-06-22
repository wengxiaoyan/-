#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mybutton.h"
#include "mywindow.h"
#include "enermy.h"
#include "waypoint.h"



MainWindow::MainWindow(QWidget *parent)

    : QMainWindow(parent)

    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);

    //用于绘画窗口

    MyButton* btn = new MyButton(":/1");

    //载入按钮图片

    btn->setParent(this);

    //载入按钮在哪个窗口显示

    btn->move(325,450);

    //载入按钮位置

    MyWindow* scene = new MyWindow;

    //创建了第二个窗口

    connect(btn,&MyButton::clicked,this,[=](){

        btn->zoomdown();

        btn->zoomup();

        QTimer::singleShot(400,this,[=](){

            this->hide();

            scene->show();

        });

        //接下来开始载入敌人

        int enemyStartInterval[] = { 1400, 3400, 5400};

        WayPoint *startWayPoint = scene->waypoint_list.back(); // 这里是个逆序的，尾部才是其实节点0

        for (int i = 0; i < 3; ++i){

            QTimer::singleShot(enemyStartInterval[i],this,[=](){

                for (int i = 0; i < 3; ++i) {

                    Enermy *enemy = new Enermy(startWayPoint, scene);

                    enemy->doActivate();

                    scene->enermy_list.push_back(enemy);
                }

            });
        }

    });

    //这个函数用于连接信号与槽，第一个位置是发出信号对象的指针，第二个位置是发出信号的函数去掉（），第三个是接受对象的指针，第四个用lamda表达式写执行命令

    //在这里具体是把界面一的开始按钮与窗口一隐藏，窗口二创建联系起来。

    connect(scene,&MyWindow::chooseBack,this,[=](){

        scene->hide();

        this->show();

    });

    //把收到chooseBack信号与窗口二隐藏，窗口一出现联系起来。

    this->setFixedSize(800,600);

    //确定主界面大小

}



MainWindow::~MainWindow()

{

    delete ui;

}



void MainWindow::paintEvent(QPaintEvent *){

    QPainter painter(this);

    //定义了一个QPainter类，通过初始化确定了在哪画（在mainwindoe上画）

    QPixmap pixmap(":/2");

    //定义了一个QPixmap类，初始化了图片。

    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

    //调用QPainter的成员函数，确定了在mainwindow上画什么样的图

}
