#ifndef MYOBJECT_H
#define MYOBJECT_H
#include <QObject>
#include <QPropertyAnimation>
#include <QPoint>
#include <QPixmap>
#include <QPainter>

class MyWindow;

class MyObject : public QObject

{

    Q_OBJECT

    Q_PROPERTY(QPoint currentPos READ getCurrentPos WRITE setCurrentPos)

public:

    MyObject(QPoint startPos, QPoint targetPos, QString fileName, MyWindow * window);

    void draw(QPainter* painter);

    void move();

    QPoint getCurrentPos();

    void setCurrentPos(QPoint pos);

private slots:
    void hitTarget();

private:

    QPoint startPos;

    QPoint targetPos;

    QPoint currentPos;

    QPixmap pixmap;

    MyWindow * bullet_window;
    

signals:

};

#endif // MYOBJECT_H
