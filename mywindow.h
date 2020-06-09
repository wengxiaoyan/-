#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class MyWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);

signals:
    void chooseBack();

};

#endif // MYWINDOW_H
