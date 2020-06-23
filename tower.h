#ifndef TOWER_H
#define TOWER_H
#include <QPoint>
#include <QObject>
#include <QList>
#include <QPixmap>
#include "mywindow.h"
#include "myobject.h"

class MyObject;

class MyWindow;

class Tower : public QObject

{

    Q_OBJECT

public:

    Tower(QPoint pos, QString pixFileName, MyWindow * game );

    void draw(QPainter* painter);

    QPoint getpos();

private:

    QPoint pos;

    QPixmap pixmap;

    int attackRange = 130;//攻击范围

    int damage;//攻击力

    int fireRate;//攻速

    MyWindow * tower_window;

    QList<MyObject *> tower_bullet;


signals:

};

#endif // TOWER_H
