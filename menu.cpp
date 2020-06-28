#include "menu.h"

Menu::Menu(QPoint pos, QString pixFileName, MyWindow * game )
    :m_pos(pos)
    ,m_sprite(pixFileName)
    ,menuWindow(game)
{

}


void Menu::draw(QPainter *painter) {
    static const QPoint offsetPoint(-22, -22);
    painter->translate(m_pos);
    painter->drawPixmap(-offsetPoint,m_sprite);
}
