#ifndef LINE_H
#define LINE_H

#include <QWidget>
#include <QGraphicsItem>
#include <QDebug>

class Line : public QGraphicsItem
{
public:
    Line(QPoint pos);

    void adjust();

    enum { Type = UserType + 2 };
    int type() const Q_DECL_OVERRIDE { return Type; }

protected:
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // LINE_H
