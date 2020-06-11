#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "tower.h"
//想要用QList<Tower*>tower_list
#include <QList>

class MyWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void set_tower();
private:
    QList<Tower*>tower_list;
    //我是把它当作一个Tower类的动态数组
signals:
    void chooseBack();

};

#endif // MYWINDOW_H
