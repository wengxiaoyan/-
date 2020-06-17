#ifndef ENERMY_H
#define ENERMY_H
#include <QPoint>
#include <QPixmap>
#include "waypoint.h"
#include "mywindow.h"
#include <QtMath>
#include <QVector2D>
#include <QObject>


class Enermy : public QObject
{
    Q_OBJECT

public:

    Enermy(WayPoint *startWayPoint, MyWindow *game);

    void draw(QPainter *painter);

    void move();


    bool collisionWithCircle(QPoint point1, int radius1, QPoint point2, int radius2);

    void doActivate();

private:

    int maxHp;

    int currentHp;

    double walkingSpeed;

    bool action;

    double rotationPixmap;

    QPoint pos;

    QPixmap pixmap = QPixmap(":/2");

    WayPoint * destinationWayPoint;

    MyWindow * _game;

};

#endif // ENERMY_H
