#ifndef BULLET_H
#define BULLET_H
#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QObject>
#include <QPainter>
#include "enermy.h"
#include "mywindow.h"

class Enermy;

class MyWindow;

class Bullet : QObject
{
    Q_OBJECT

    Q_PROPERTY(QPoint _currentPos READ currentPos WRITE setCurrentPos)

public:

    Bullet(QPoint startPos, QPoint targetPoint, int damage, Enermy *target,
           MyWindow *game, const QPixmap &sprite = QPixmap(":/5"));

    void draw(QPainter *painter);

    void move();

    void setCurrentPos(QPoint pos);

    QPoint currentPos();

private slots:

    void hitTarget();

private:

    QPoint startPos;

    QPoint targetPos;

    QPixmap pixmap;

    QPoint _currentPos;

    Enermy * target;

    MyWindow * _game3;

    int	damage;

    static const QSize ms_fixedSize;
};

#endif // BULLET_H
