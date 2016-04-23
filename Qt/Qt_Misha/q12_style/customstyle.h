#ifndef CUSTOMSTYLE_H
#define CUSTOMSTYLE_H

#include <QtWidgets>
#include <QProxyStyle>

class QPainter;

class CustomStyle : public QProxyStyle
{
public:
    void polish (QWidget* pwgt);
    void unpolish(QWidget* pwgt);
    void drawPrimitive(PrimitiveElement elem, const QStyleOption* popt, QPainter* ppainter, const QWidget* pwgt = 0) const;
    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = 0) const;
};

#endif // CUSTOMSTYLE_H
