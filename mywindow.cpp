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
    /*MyButton* setTower = new MyButton(":/7");
    //建塔按钮
    setTower->setParent(this);
    //建塔按钮出现窗口
    setTower->move(50,100);
    //建塔按钮出现位置
    connect(setTower,&MyButton::clicked,this,&MyWindow::addMyObject{
        MyWindow::set_tower();

    });

    //把建塔建和建塔连接*/
    loadTowerPositions();//创建塔的基座？
    connect(back_btn,&MyButton::clicked,this,[=](){
        back_btn->zoomdown();
        back_btn->zoomup();
        QTimer::singleShot(400,this,[=](){
            emit chooseBack();
        });
    });
    //连接返回键与信号发射功能
    QTimer* timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MyWindow::updateScene);
    timer->start(10);
}

void MyWindow::mousePressEvent(QMouseEvent *event){
    QPoint pressPos = event->pos();
    auto it = towerposition_list.begin();//auto的意思是使it的变量类型与等号后面的类型相同
    for (;it!=towerposition_list.end();++it) {
        if (canBuyTower() && it->containPoint(pressPos) && !it->hasTower())
        {
            it->setHasTower();
            Tower *tower = new Tower(it->showPos(), ":/4");
            tower_list.push_back(tower);
            update();
            break;
        }
    }
}

bool MyWindow::canBuyTower() const
{
    return true;
}

void MyWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    //在scene上画图
    QPixmap pixmap(":/3");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
    //调用painter的成员函数实现绘图
    foreach(TowerPosition towerposition, towerposition_list)
        towerposition.draw(&painter);
    foreach(Tower* tower, tower_list)//遍历list，将tower_list的所有成员一次赋给tower
        tower->draw(&painter);
    //绘制
    foreach(MyObject* object, object_list)
        object->draw(&painter);
}

void MyWindow::set_tower()
{
    Tower* a_new_tower = new Tower(QPoint(100,70),":/4");
    tower_list.push_back(a_new_tower);
    update();//重新绘制窗口
}

void MyWindow::addMyObject(){
    MyObject* object = new MyObject(QPoint(100,100),QPoint(400,400),":/8");
    object_list.push_back(object);
    object->move();
    update();
}

void MyWindow::updateScene(){
    update();
}

void MyWindow::loadTowerPositions(){
    QPoint pos[] =
    {
        QPoint(100, 430),
        QPoint(250, 430),
        QPoint(400, 430),
        QPoint(550, 430),
        QPoint(200, 250),
        QPoint(350, 250),
        QPoint(500, 250),
        QPoint(650, 250),
        QPoint(50, 100),
        QPoint(250, 100),
        QPoint(450, 100),
        QPoint(650, 100)
    };
    int len	= sizeof(pos) / sizeof(pos[0]);
    for (int i = 0; i < len; ++i)
        towerposition_list.push_back(pos[i]);
}
