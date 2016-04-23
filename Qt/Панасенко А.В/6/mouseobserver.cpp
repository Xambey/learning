#include "MouseObserver.h"
// ----------------------------------------------------------------------
MouseObserver::MouseObserver(QWidget* pwgt /*= 0*/) : QLabel(pwgt)
{
    setAlignment(Qt::AlignCenter);
    setText("Mouse interactions\n(Press a mouse button)");
    timer.start(1, this);
    r = 0;
    g = 0;
    b = 0;
}
// ----------------------------------------------------------------------
/*virtual*/void MouseObserver::mousePressEvent(QMouseEvent* pe)
{
    dumpEvent(pe, "Mouse Pressed");
}
/*virtual*/void MouseObserver::mouseReleaseEvent(QMouseEvent* pe)
{
    dumpEvent(pe, "Mouse Released");
}
// ----------------------------------------------------------------------
/*virtual*/ void MouseObserver::mouseMoveEvent(QMouseEvent* pe)
{
    dumpEvent(pe, "Mouse Is Moving");
}


void MouseObserver::keyPressEvent(QKeyEvent* pe)
{
    QString str;
    str += "Keyboard:\n";
    str += "button: " + QString::number(pe->key()) + "\n";
    if(pe->modifiers() & Qt::ShiftModifier) {
        str += "Shift ";
    }
    if(pe->modifiers() & Qt::ControlModifier) {
        str += "Control ";
    }
    if(pe->modifiers() & Qt::AltModifier) {
        str += "Alt";
    }
    setText(str);
}

void MouseObserver::timerEvent(QTimerEvent *)
{
    r += 0.02f;
    g += 0.05f;
    b += 0.05f;
    if(r > 255 )
        r -= 255;
    if(g > 255 )
        g -= 255;
    if(b > 255 )
        b -= 255;
    QPalette pal;
    pal.setColor(QPalette::Background, QColor(r,g,b));
    setPalette(pal);
}

void MouseObserver::wheelEvent(QWheelEvent *pe)
{
    QString str;
    str += "Wheel:\n";
    str += QString::number(pe->delta()) + "\n";
    str += "X = " + QString::number(pe->globalX()) + "\n";
    str += "Y = " + QString::number(pe->globalY()) + "\n";
    if(pe->modifiers() & Qt::ShiftModifier) {
        str += "Shift ";
    }
    if(pe->modifiers() & Qt::ControlModifier) {
        str += "Control ";
    }
    if(pe->modifiers() & Qt::AltModifier) {
        str += "Alt";
    }
    setText(str);
}



// ----------------------------------------------------------------------
void MouseObserver::dumpEvent(QMouseEvent* pe, const QString& strMsg)
{
    setText(strMsg
    + "\n buttons()=" + buttonsInfo(pe)
    + "\n x()=" + QString::number(pe->x())
    + "\n y()=" + QString::number(pe->y())
    + "\n globalX()=" + QString::number(pe->globalX())
    + "\n globalY()=" + QString::number(pe->globalY())
    + "\n modifiers()=" + modifiersInfo(pe)
    );
    }
// ----------------------------------------------------------------------
QString MouseObserver::modifiersInfo(QMouseEvent* pe)
{
    QString strModifiers;
    if(pe->modifiers() & Qt::ShiftModifier) {
        strModifiers += "Shift ";
    }
    if(pe->modifiers() & Qt::ControlModifier) {
        strModifiers += "Control ";
    }
    if(pe->modifiers() & Qt::AltModifier) {
        strModifiers += "Alt";
    }
    return strModifiers;
}

// ----------------------------------------------------------------------
QString MouseObserver::buttonsInfo(QMouseEvent* pe)
{
    QString strButtons;
    if(pe->buttons() & Qt::LeftButton) {
        strButtons += "Left ";
    }
    if(pe->buttons() & Qt::RightButton) {
        strButtons += "Right ";
    }
    if(pe->buttons() & Qt::MidButton) {
        strButtons += "Middle";
    }

    return strButtons;
}
