#include "MouseObserver.h"
#include "qdebug.h"


float MouseObserver::getB() const
{
    return blue;
}

void MouseObserver::setB(float value)
{
    blue = value;
}

bool MouseObserver::getNeedSave() const
{
    return 1;//needSave;
}

MouseObserver::MouseObserver(QWidget* pwgt /*= 0*/) : QLabel(pwgt)
{
    setAlignment(Qt::AlignCenter);
    installEventFilter(new CloseFilter());
    timer.start(1, this);
    blue = 0;
    invert = false;
}

void MouseObserver::mousePressEvent(QMouseEvent* pe)
{
    dumpEvent(pe, "Mouse Pressed");
}

void MouseObserver::mouseReleaseEvent(QMouseEvent* pe)
{
    dumpEvent(pe, "Mouse Released");
}

void MouseObserver::mouseMoveEvent(QMouseEvent* pe)
{
    dumpEvent(pe, "Mouse Is Moving");
}

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

void MouseObserver::keyPressEvent(QKeyEvent *ev)
{
    QString msg;
    msg += "keyPressEvent\n";
    msg += "buttons = " + QString::number(ev->key()) + '\n';

    if(ev->modifiers() & Qt::ShiftModifier) {
        msg += "Shift ";
    }
    if(ev->modifiers() & Qt::ControlModifier) {
        msg += "Control ";
    }
    if(ev->modifiers() & Qt::AltModifier) {
        msg += "Alt";
    }
    setText(msg);
}

void MouseObserver::timerEvent(QTimerEvent *ev)
{
    blue += 0.5f * !invert;
    blue -= 0.5f * invert;

    if(blue > 255)
        invert = true;
    if(blue < 0)
        invert = false;

    QPalette p;
    p.setColor(QPalette::Background, QColor(128, 128, blue));
    setPalette(p);

    QWidget::timerEvent(ev);
}

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
