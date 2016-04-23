#include "line.h"
#include <QPainter>

Line::Line(QPoint pos)
{
    moveBy(pos.x(), pos.y());
}

void Line::adjust()
{
}

QRectF Line::boundingRect() const
{
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(QPen(QColor(145, 72, 20), 8, Qt::SolidLine));
    painter->drawLine(0, 0, 0, 235 + 64);
    painter->setPen(QPen(QColor(91, 44, 12), 8, Qt::SolidLine));
    painter->drawLine(0, -10, 0, 235 + 64);

    painter->drawImage(QRectF(-64, 235,128,128), QImage("ball.png"));
}
