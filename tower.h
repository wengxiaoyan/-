#ifndef TOWER_H
#define TOWER_H
#include <QPoint>
#include <QObject>
#include <QPixmap>
#include "enermy.h"
#include <QTimer>

class MyWindow;

class Enermy;

class Tower : public QObject

{

    Q_OBJECT

public:

    Tower(QPoint pos, QString pixFileName, MyWindow * _game1 );

    void draw(QPainter* painter);

    void targetKilled();

    void attackEnermy();

    void chooseEnemyForAttack(Enermy *enemy);

    void shootWeapon();

    void lostSightOfEnemy();

private:

    QPoint pos;

    QPixmap pixmap;

    int attackRange = 130;//攻击范围

    int damage;//攻击力

    int fireRate;//攻速

    double rotationPixmap;

    Enermy * chooseEnermy;

    QTimer * fireRateTimer;

    MyWindow * _game2;

signals:

};

#endif // TOWER_H
