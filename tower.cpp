#include "tower.h"
#include "bullet.h"
#include "mywindow.h"
#include "enermy.h"
#include <QPoint>
#include <QObject>
#include <QPainter>

Tower::Tower(QPoint pos, QString pixFileName, MyWindow * _game1) : QObject(0),pixmap(pixFileName)
{
    this->pos = pos;
    _game2 = _game1;
}

void Tower::draw(QPainter* painter){
    painter->save();
    painter->setPen(Qt::white);
    static const QPoint offsetPoint(22, 22);
    painter->translate(pos);// 这里将坐标原点移到pos
    painter->drawPixmap(-offsetPoint,pixmap);
    painter->drawEllipse(offsetPoint, attackRange, attackRange);//画攻击范围
    painter->restore();
}



void Tower::attackEnermy()

{

    // 启动打炮模式

    fireRateTimer->start(fireRate);

}

void Tower::chooseEnemyForAttack(Enermy *enemy)

{

    // 选择敌人,同时设置对敌人开火

    chooseEnermy = enemy;

    // 这里启动timer,开始打炮

    attackEnermy();

    // 敌人自己要关联一个攻击者,这个用QList管理攻击者,因为可能有多个

    chooseEnermy->getAttacked(this);

}

void Tower::shootWeapon()

{

    // 每次攻击,产生一个子弹

    // 子弹一旦产生,交由m_game管理,进行绘制

    Bullet *bullet = new Bullet(pos, chooseEnermy->_pos(), damage, chooseEnermy, _game2);

    bullet->move();

    _game2->addBullet(bullet);

}

void Tower::targetKilled()

{

    // 目标死亡时,也需要取消关联

    // 取消攻击

    if (chooseEnermy)

        chooseEnermy = NULL;

    fireRateTimer->stop();

    rotationPixmap = 0.0;

}

void Tower::lostSightOfEnemy()

{

    // 当敌人脱离炮塔攻击范围,要将炮塔攻击的敌人关联取消

    // 同时取消攻击

    chooseEnermy->gotLostSight(this);

    if (chooseEnermy)

        chooseEnermy = NULL;

    fireRateTimer->stop();

    rotationPixmap = 0.0;

}


