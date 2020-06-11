#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>

class MyButton : public QPushButton
//创建了一个按钮类
{
    Q_OBJECT
public:
    MyButton(QString pix);
    void zoomdown();
    void zoomup();

signals:

};

#endif // MYBUTTON_H
