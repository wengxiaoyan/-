#include "tower.h"
#include "mywindow.h"
#include "myobject.h"
#include <QPoint>
#include <QObject>
#include <QPainter>

Tower::Tower(QPoint pos, QString pixFileName, MyWindow * game ) : QObject(0),pixmap(pixFileName)
{

    this->pos = pos;

    tower_window = game;

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

QPoint Tower::getpos(){
    return pos;
}
