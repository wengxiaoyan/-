#include "mywindow.h"
#include "mybutton.h"
#include <QTimer>
#include <QPaintEvent>
#include <QPainter>

MyWindow::MyWindow(QWidget *parent) :

  QMainWindow(parent)

  ,m_waves(0)

  ,m_gameWin(false)

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

    /*MyButton* setBullet = new MyButton(":/7");
    //建塔按钮
    setBullet->setParent(this);
    //建塔按钮出现窗口
    setBullet->move(100,50);
    //建塔按钮出现位置
    connect(setBullet,&MyButton::clicked,this,&MyWindow::addMyBullet);
    //把建塔建和建塔连接*/


    loadTowerPositions();//创建塔的基座

    addWayPoints();//创建节点

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

void MyWindow::addMyBullet(Tower * tower, Enermy * enermy){

    MyObject* object = new MyObject(tower->getpos(),enermy->getpos(),":/5", this, enermy, tower);

    object_list.push_back(object);

    object->move();

}



//通过点击鼠标事件来判定是否建塔,并且在完成建塔操作后发射子弹

void MyWindow::mousePressEvent(QMouseEvent *event){

    QPoint pressPos = event->pos();

    auto it = towerposition_list.begin();//auto的意思是使it的变量类型与等号后面的类型相同

    for (;it!=towerposition_list.end();++it) {

        if (canBuyTower() && it->containPoint(pressPos) && !it->hasTower())

        {
            it->setHasTower();

            Tower *tower = new Tower(it->showPos(), ":/4", this);

            tower_list.push_back(tower);

            update();

            break;
        }
    }
}



//判定钱够不够建塔（虽然当前版本还没实现钱的功能，但是这是为后来版本做的准备）

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

    foreach(MyObject* object, object_list)

        object->draw(&painter);

    foreach(WayPoint* waypoint, waypoint_list)

        waypoint->draw(&painter);

    foreach (Enermy *enemy, enermy_list)

        enemy->draw(&painter);

}

/*void MyWindow::set_tower()
{
    Tower* a_new_tower = new Tower(QPoint(100,70),":/4");
    tower_list.push_back(a_new_tower);
    update();//重新绘制窗口
}*/

void MyWindow::updateScene(){

    foreach (Enermy *enemy, enermy_list)

            enemy->move();

    update();

}
//添加塔基座的点

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

void MyWindow::addWayPoints()

{

    WayPoint *wayPoint1 = new WayPoint(QPoint(700, 540));

    waypoint_list.push_back(wayPoint1);

    WayPoint *wayPoint2 = new WayPoint(QPoint(55, 540));

    waypoint_list.push_back(wayPoint2);

    wayPoint2->setNextWayPoint(wayPoint1);

    WayPoint *wayPoint3 = new WayPoint(QPoint(55, 365));

    waypoint_list.push_back(wayPoint3);

    wayPoint3->setNextWayPoint(wayPoint2);

    WayPoint *wayPoint4 = new WayPoint(QPoint(737, 365));

    waypoint_list.push_back(wayPoint4);

    wayPoint4->setNextWayPoint(wayPoint3);

    WayPoint *wayPoint5 = new WayPoint(QPoint(737, 190));

    waypoint_list.push_back(wayPoint5);

    wayPoint5->setNextWayPoint(wayPoint4);

    WayPoint *wayPoint6 = new WayPoint(QPoint(55, 190));

    waypoint_list.push_back(wayPoint6);

    wayPoint6->setNextWayPoint(wayPoint5);

}

//void MyWindow::getHpDamage(int damage/* = 1*/)

//{

    // 暂时空实现，以后这里进行基地费血行为

//    }

void MyWindow::removedEnemy(Enermy *enemy)

{

    Q_ASSERT(enemy);

    enermy_list.removeOne(enemy);

    delete enemy;

    /*if (enermy_list.isEmpty())
    {
        m_gameWin = true;
            // 游戏胜利转到游戏胜利场景
            // 这里暂时以打印处理
     }*/

}

/*bool MyWindow::loadWave()
{
    if (m_waves >= 6)
        return false;
    WayPoint *startWayPoint = waypoint_list.back(); // 这里是个逆序的，尾部才是其实节点
    int enemyStartInterval[] = { 100, 500, 600, 1000, 3000, 6000 };
    QPixmap sprite = QPixmap(":/8");
    for (int i = 0; i < 6; ++i)
    {
        Enermy *enemy = new Enermy(startWayPoint, this);
        enermy_list.push_back(enemy);
        QTimer::singleShot(enemyStartInterval[i], enemy, SLOT(doActivate()));
    }
    return true;
}*/

void MyWindow::removedBullet(MyObject * bullet)

{

    Q_ASSERT(bullet);

    object_list.removeOne(bullet);

    delete bullet;

}
