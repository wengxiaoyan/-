#ifndef TOWERPOSITION_H
#define TOWERPOSITION_H
#include <QPixmap>
#include <QPoint>
#include <QSize>

class TowerPosition{
public:
    TowerPosition(QPoint pos);
    void setHasTower(bool hasTower = true);
    bool hasTower() const;
    const QPoint centerPos() const;
    bool containPoint(const QPoint &pos) const;
    void draw(QPainter *painter) const;
    QPoint showPos();
private:
    QPoint		m_pos;
    bool		m_hasTower;
    QPixmap m_sprite = QPixmap(":/7");
    static const QSize ms_fixedSize;
};



#endif // TOWERPOSITION_H
