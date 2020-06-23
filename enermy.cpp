#include "enermy.h"

Enermy::Enermy(WayPoint *startWayPoint, MyWindow *game)

    : QObject(0)

    , pos(startWayPoint->pos())

{

    maxHp = 80;

    currentHp = 80;

    action = false;

    walkingSpeed = 1.0;

    destinationWayPoint = startWayPoint->nextWayPoint();

    rotationPixmap = 0.0;

    _game = game;

}

bool Enermy::collisionWithCircle(QPoint point1, int radius1, QPoint point2, int radius2)

{

    const int xdif = point1.x() - point2.x();

    const int ydif = point1.y() - point2.y();

    const int distance = qSqrt(xdif * xdif + ydif * ydif);

    if (distance <= radius1 + radius2)

        return true;

    return false;

}

void Enermy::draw(QPainter *painter)

{

    if (!action)

        return;

    // 血条的长度

    // 其实就是2个方框,红色方框表示总生命,固定大小不变

    // 绿色方框表示当前生命,受m_currentHp / m_maxHp的变化影响

    static const int Health_Bar_Width = 20;

    painter->save();

    QPoint healthBarPoint = pos + QPoint(-Health_Bar_Width / 2 - 5, - 50 );

    // 绘制血条

    painter->setPen(Qt::NoPen);

    painter->setBrush(Qt::red);

    QRect healthBarBackRect(healthBarPoint, QSize(Health_Bar_Width, 2));

    painter->drawRect(healthBarBackRect);

    painter->setBrush(Qt::green);

    QRect healthBarRect(healthBarPoint, QSize((double)currentHp / maxHp * Health_Bar_Width, 2));

    painter->drawRect(healthBarRect);

    // 绘制偏转坐标,由中心+偏移=左上

    static const QPoint offsetPoint(- 44 / 2, - 44 / 2);

    painter->translate(pos);

    painter->rotate(rotationPixmap);

    // 绘制敌人

    painter->drawPixmap(offsetPoint, pixmap);

    painter->restore();

}

void Enermy::move()//移动的同时顺便检查一下血量

{

    if (!action)

        return;

    if(currentHp<=0){

        _game->removedEnemy(this);

        return;
    }

    if (collisionWithCircle(pos, 1, destinationWayPoint->pos(), 1))

    {

        // 敌人抵达了一个航点

        if (destinationWayPoint->nextWayPoint())

        {

            // 还有下一个航点

            pos = destinationWayPoint->pos();

            destinationWayPoint = destinationWayPoint->nextWayPoint();

        }

        else

       {

            // 表示进入基地

            //_game->getHpDamage();

            _game->removedEnemy(this);

            return;

        }

    }

    // 还在前往航点的路上

    // 目标航点的坐标

    QPoint targetPoint = destinationWayPoint->pos();

    // 未来修改这个可以添加移动状态,加快,减慢,m_walkingSpeed是基准值

    // 向量标准化

    double movementSpeed = walkingSpeed;

    QVector2D normalized(targetPoint - pos);

    normalized.normalize();//单位向量

    pos = pos + normalized.toPoint() * movementSpeed;

    // 确定敌人选择方向

    // 默认图片向左,需要修正180度转右

    rotationPixmap = qRadiansToDegrees(qAtan2(normalized.y(), normalized.x())) + 180;

}

void Enermy::doActivate()

{

    action = true;

}

QPoint Enermy::getpos(){

    return pos;

}

int Enermy::showCurrentHp(){
    return currentHp;
}

void Enermy::setCurrentHp(int current_hp){
    currentHp = current_hp;
}
