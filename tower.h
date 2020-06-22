#ifndef TOWER_H
#define TOWER_H
#include <QPoint>
#include <QObject>
#include <QPixmap>

class Tower : public QObject

{

    Q_OBJECT

public:

    Tower(QPoint pos, QString pixFileName );

    void draw(QPainter* painter);

private:

    QPoint pos;

    QPixmap pixmap;

    int attackRange = 130;//攻击范围

    int damage;//攻击力

    int fireRate;//攻速


signals:

};

#endif // TOWER_H
