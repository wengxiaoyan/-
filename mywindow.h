#ifndef MYWINDOW_H
#define MYWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include "tower.h"
#include "myobject.h"
#include "towerposition.h"
#include "waypoint.h"
#include "enermy.h"
//想要用QList<Tower*>tower_list

#include <QList>

class Enermy;

class Bullet;

class Tower;

class MyWindow : public QMainWindow

{

    Q_OBJECT

public:

    explicit MyWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);

    //void set_tower();

    void addMyBullet(Tower * tower, Enermy * enermy);

    void updateScene();

    void loadTowerPositions();

    void mousePressEvent(QMouseEvent *event);

    bool canBuyTower() const;

    void addWayPoints();

    //bool loadWave();

    void removedEnemy(Enermy *enemy);

    void removedBullet(MyObject * bullet);

    //void getHpDamage(int damage/* = 1*/);









    QList<Tower*>tower_list;

    //我是把它当作一个Tower类的动态数组

    QList<MyObject*> object_list;

    QList<TowerPosition> towerposition_list;

    QList<WayPoint *> waypoint_list;

    QList<Enermy *> enermy_list;

    int m_waves;

    bool m_gameWin;

signals:

    void chooseBack();

};

#endif // MYWINDOW_H
