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
    QPoint _pos;
    QPixmap pixmap;
signals:

};

#endif // TOWER_H
