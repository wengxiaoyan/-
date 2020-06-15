#include "waypoint.h"


WayPoint::WayPoint(QPoint pos): _pos(pos), _nextWayPoint(NULL){}


void WayPoint::setNextWayPoint(WayPoint *nextPoint){
    _nextWayPoint = nextPoint;
}

WayPoint* WayPoint::nextWayPoint() const{
    return _nextWayPoint;
}

const QPoint WayPoint::pos() const{
    return _pos;
}

void WayPoint::draw(QPainter *painter) const
{
    painter->save();
    painter->setPen(QColor(0, 255, 0));
    painter->drawEllipse(_pos, 6, 6);
    painter->drawEllipse(_pos, 2, 2);
    if (_nextWayPoint)
        painter->drawLine(_pos, _nextWayPoint->_pos);
    painter->restore();
}
