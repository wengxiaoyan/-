#include "bullet.h"
#include "enermy.h"
#include "mainwindow.h"
#include <QPainter>
#include <QPropertyAnimation>

const QSize Bullet::ms_fixedSize(8, 8);

Bullet::Bullet(QPoint startPos, QPoint targetPoint, int damage, Enermy *target,
               MyWindow *game, const QPixmap &sprite/* = QPixmap(":/5")*/)

    : startPos(startPos)

    , targetPos(targetPoint)

    , pixmap(sprite)

    , _currentPos(startPos)

    , target(target)

    , _game3(game)

    , damage(damage)

{

}

void Bullet::draw(QPainter *painter)

{

    painter->drawPixmap(_currentPos, pixmap);

}

void Bullet::move()

{

    // 100毫秒内击中敌人

    static const int duration = 100;

    QPropertyAnimation *animation = new QPropertyAnimation(this, "_currentPos");

    animation->setDuration(duration);

    animation->setStartValue(startPos);

    animation->setEndValue(targetPos);

    connect(animation, SIGNAL(finished()), this, SLOT(hitTarget()));

    animation->start();

}

void Bullet::hitTarget()
{
    // 这样处理的原因是:
    // 可能多个炮弹击中敌人,而其中一个将其消灭,导致敌人delete
    // 后续炮弹再攻击到的敌人就是无效内存区域
    // 因此先判断下敌人是否还有效

    if (_game3->enermy_list.indexOf(target) != -1)

        target->getDamage(damage);

    _game3->removedBullet(this);

}

void Bullet::setCurrentPos(QPoint pos)

{

    _currentPos = pos;

}

QPoint Bullet::currentPos()

{

    return _currentPos;

}
