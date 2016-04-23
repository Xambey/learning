#ifndef STYLE_H
#define STYLE_H
#include <QtWidgets>
#include <QProxyStyle>

class QPainter;

class style : public QProxyStyle
{
public:
    void polish (QWidget* pwgt);
    void unpolish(QWidget* pwgt);
    void drawPrimitive(PrimitiveElement elem, const QStyleOption* popt, QPainter* ppainter, const QWidget* pwgt = 0) const;
    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = 0) const;

};

#endif // STYLE_H
