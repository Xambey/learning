#include "style.h"

void style::polish(QWidget* pwgt)
{
    if (qobject_cast<QPushButton*>(pwgt))
        pwgt->setAttribute(Qt::WA_Hover, true);
}


void style::unpolish(QWidget* pwgt)
{
    if (qobject_cast<QPushButton*>(pwgt))
        pwgt->setAttribute(Qt::WA_Hover, false);
}


void style::drawPrimitive(PrimitiveElement elem, const QStyleOption* popt, QPainter* ppainter, const QWidget* pwgt) const
{
    QPixmap pix;
    if((popt->state & State_Sunken) || (popt->state & State_On))
        pix = QPixmap("Knopka_press.png");
    else
        pix = QPixmap("Knopka_unpress.png");

    ppainter->drawPixmap(popt->rect, pix);

    if ((popt->state & State_Enabled) && (popt->state & State_MouseOver))
            ppainter->fillRect(popt->rect, QColor(25, 97, 45, .2));
}

void style::drawControl(QStyle::ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    QPixmap pix;
    if((option->state & State_Sunken) || (option->state & State_On))
        pix = QPixmap("Knopka_press.png");
    else
        pix = QPixmap("Knopka_unpress.png");

    painter->drawPixmap(option->rect, pix);
}


