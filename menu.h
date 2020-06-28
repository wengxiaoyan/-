#ifndef MENU_H
#define MENU_H


#include <QPixmap>
#include <QPoint>
#include <QSize>
#include <QPainter>
#include "mywindow.h"

class MyWindow;

class Menu{
public:
    Menu(QPoint pos, QString pixFileName, MyWindow * game );
    bool containPoint(const QPoint &pos) const;
    void draw(QPainter *painter);
private:
    QPoint		m_pos;
    QPixmap m_sprite/* = QPixmap(":/7")*/;
    static const QSize ms_fixedSize;
    MyWindow * menuWindow;
};


#endif // MENU_H
