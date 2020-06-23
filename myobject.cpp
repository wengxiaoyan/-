#include "myobject.h"
#include "mywindow.h"
#include <QPropertyAnimation>

MyObject::MyObject(QPoint startPos, QPoint targetPos, QString fileName, MyWindow * window) : QObject(0),pixmap((fileName))

{

    this->currentPos = startPos;

    this->startPos = startPos;

    this->targetPos = targetPos;

    this->bullet_window = window;

}

void MyObject::draw(QPainter* painter){

    painter->drawPixmap(currentPos,pixmap);

}

void MyObject::move(){

    QPropertyAnimation* animation = new QPropertyAnimation(this, "currentPos");

    animation->setDuration(120);

    animation->setStartValue(startPos);

    animation->setEndValue(targetPos);

    connect(animation, SIGNAL(finished()), this, SLOT(hitTarget()));

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
    bullet_window->removedBullet(this);
}
