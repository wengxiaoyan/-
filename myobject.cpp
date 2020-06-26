#include "myobject.h"
#include "mywindow.h"
#include "enermy.h"
#include "tower.h"
#include <QPropertyAnimation>

MyObject::MyObject(QPoint startPos, QPoint targetPos, QString fileName,
                   MyWindow * window, Enermy * enemy, Tower * tower)
    :QObject(0)
    ,pixmap((fileName))

{

    this->currentPos = startPos;

    this->startPos = startPos;

    this->targetPos = targetPos;

    this->bullet_window = window;

    this->target = enemy;

    this->source = tower;
}

void MyObject::draw(QPainter* painter){

    painter->drawPixmap(currentPos,pixmap);

}

void MyObject::move(){

    QPropertyAnimation* animation = new QPropertyAnimation(this, "currentPos");

    animation->setDuration(200);

    animation->setStartValue(startPos);

    animation->setEndValue(targetPos);

    connect(animation, SIGNAL(finished()), this, SLOT(hitTarget()));//保证子弹打中目标后能够消失

    animation->start();

}

QPoint MyObject::getCurrentPos(){

    return this->currentPos;

}

void MyObject::setCurrentPos(QPoint pos){

    this->currentPos = pos;

}

void MyObject::hitTarget()
{
    if(target == NULL)
        bullet_window->removedBullet(this);
    else{

    bullet_window->removedBullet(this);

    target->setCurrentHp(target->showCurrentHp() - source->showDamage());
    }
}
