#ifndef _MouseObserver_h_
#define _MouseObserver_h_

#include "qstring.h"
#include "QMouseEvent"
#include "QBasicTimer"
#include "closefilter.h"
#include "qlabel.h"

class MouseObserver : public QLabel
{
    bool invert;
    float blue;
    QBasicTimer timer;
    bool needSave;
public:
    MouseObserver(QWidget* pwgt = 0);
    float getB() const;
    void setB(float value);
    bool getNeedSave() const;

protected:
    virtual void mousePressEvent (QMouseEvent* pe);
    virtual void mouseReleaseEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent (QMouseEvent* pe);
    virtual void keyPressEvent(QKeyEvent *);
    virtual void timerEvent(QTimerEvent *ev);
    void dumpEvent (QMouseEvent* pe, const QString& strMessage);
    QString modifiersInfo (QMouseEvent* pe );
    QString buttonsInfo (QMouseEvent* pe );
};

#endif //_MouseObserver_h_
