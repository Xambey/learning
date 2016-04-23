#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <QBasicTimer>
#include <QWheelEvent>
#include "QGraphicsProxyWidget"
#include "qprogressbar"
#include "qmath.h"

class MyView: public QGraphicsView
{
    Q_OBJECT
    QBasicTimer timer;
    QProgressBar prb;
    float pull;
public:
    MyView(QGraphicsScene* pScene, QWidget* pwgt = 0)
        : QGraphicsView(pScene, pwgt)
    {
        timer.start(1000/60, this);

        prb.setFixedSize(500, 40);
        QGraphicsProxyWidget* pproxyWidget = pScene->addWidget(&prb);
        QTransform transform = pproxyWidget->transform();
        transform.translate(-170, 200);
        transform.scale(2, 2);
        transform.rotate(80, Qt::YAxis);
        transform.rotate(30, Qt::XAxis);
        pproxyWidget->setTransform(transform);
    }


protected:
    void wheelEvent(QWheelEvent* event)
    {
        if(event->delta() > 0)
            slotZoomIn();
        else
            slotZoomOut();
    }

    void timerEvent(QTimerEvent*)
    {
        prb.setValue((1+sinf(pull)) * prb.maximum()/2);
        pull+=0.1;
    }

public slots:
    void slotZoomIn()
    {
        scale(1.1, 1.1);
    }
    void slotZoomOut()
    {
        scale(1 / 1.1, 1 / 1.1);
    }
    void slotRotateLeft()
    {
        rotate(-5);
    }
    void slotRotateRight()
    {
        rotate(5);
    }
};

#endif // MYVIEW_H
