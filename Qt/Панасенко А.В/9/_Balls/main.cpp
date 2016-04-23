#include <QApplication>
#include <QGraphicsView>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QtWidgets>
#include "line.h"

#define size 114
#define c 4
#define pos_x 200
#define speed 700

QTimeLine* newAnim(Line* ball, int in, int to, QEasingCurve curve)
{
    QTimeLine *NewTimer = new QTimeLine(speed);
    NewTimer->setEasingCurve(curve);

    QGraphicsItemAnimation* anim = new QGraphicsItemAnimation();
    anim->setItem(ball);
    anim->setTimeLine(NewTimer);
    anim->setRotationAt(0, in);
    anim->setRotationAt(1, to);

    return NewTimer;
}

int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    QGraphicsView view;
    QGraphicsScene *scene = new QGraphicsScene(&view);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    Line *left, *right, *right2;

    int of = pos_x;

    for(int i = 0; i < c; i++)
    {
        Line* ball = new Line(QPoint(of, -2));
        scene->addItem(ball);
        of += size;
        if(i==0)
            left = ball;
        else if(i == c - 1)
            right = ball;
        else if(i == c - 2)
            right2 = ball;
    }

    QTimeLine *LeftTimerTo      = newAnim(left,0,45,QEasingCurve::OutQuart);
    QTimeLine *LeftTimerReturn    = newAnim(left,45,0,QEasingCurve::InQuart);
    QTimeLine *RightTimerTo     = newAnim(right,0,-45,QEasingCurve::OutQuart);
    QTimeLine *RightTimerBack   = newAnim(right,-45,0,QEasingCurve::InQuart);
    QTimeLine *RightTimerTo2     = newAnim(right2,0,-45,QEasingCurve::OutQuart);
    QTimeLine *RightTimerBack2   = newAnim(right2,-45,0,QEasingCurve::InQuart);



    scene->setSceneRect(0, 0, 940, 460);

    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    view.setScene(scene);
    view.resize(960, 480);
    view.show();

    QObject::connect(LeftTimerTo,   SIGNAL(finished()), LeftTimerReturn,  SLOT(start()));
    QObject::connect(LeftTimerReturn, SIGNAL(finished()), RightTimerTo,   SLOT(start()));
    QObject::connect(LeftTimerReturn, SIGNAL(finished()), RightTimerTo2,   SLOT(start()));
    QObject::connect(RightTimerTo,  SIGNAL(finished()), RightTimerBack, SLOT(start()));
    QObject::connect(RightTimerTo2,  SIGNAL(finished()), RightTimerBack2, SLOT(start()));
    QObject::connect(RightTimerBack,SIGNAL(finished()), LeftTimerTo,    SLOT(start()));

    LeftTimerReturn->start();

    return app.exec();
}


