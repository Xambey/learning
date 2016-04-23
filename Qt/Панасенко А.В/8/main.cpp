#include <QApplication>
#include <QWidget>
#include <QSplitter>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTreeView>
#include <QLabel>
#include <QScrollArea>
#include <QScrollBar>
#include <QFormLayout>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QScrollArea* form = new QScrollArea;

    form->resize(600, 600);
    QScrollBar* bar = new QScrollBar;

    QWidget* pwgt1 = new QWidget(form);
    QPalette pal1;
   // QScrollArea* form2 = new QScrollArea;
    //form->setWidget(pwgt1);

    pal1.setColor(pwgt1->backgroundRole(), Qt::green);
    pwgt1->setPalette(pal1);
    //pwgt1->resize(500, 500);
    //pwgt1->move(0, 0);
    pwgt1->setAutoFillBackground(true);
    pwgt1->setCursor(Qt::PointingHandCursor);
    pwgt1->show();

    QPixmap pix("tree.jpg");


    QScrollArea* form2 = new QScrollArea;
    QWidget* pwgt2 = new QWidget(form2);

    form2->setWidget(pwgt2);

    QWidget* pwgt3 = new QWidget(form);
    QPalette pal2;
    QPalette pal3;
    form->setWidget(pwgt1);

    pal3.setBrush(pwgt2->backgroundRole(), Qt::yellow);
    pwgt3->setPalette(pal2);
    pwgt3->setCursor(Qt::ForbiddenCursor);
    pwgt3->resize(300, 300);
    //pwgt2->move(500, 0);
    pwgt3->setAutoFillBackground(true);
    pwgt3->show();

    form->setWidget(pwgt1);

    pal2.setBrush(pwgt2->backgroundRole(), QBrush(pix));
    pal2.setColor(pwgt2->backgroundRole(), Qt::blue);
    pwgt2->setPalette(pal2);
    pwgt2->setCursor(Qt::ForbiddenCursor);
    pwgt2->resize(300, 300);
    //pwgt2->move(500, 0);
    pwgt2->setAutoFillBackground(true);
    pwgt2->show();


    QPalette pal = pwgt2->palette();

    QFrame* obj = new QFrame(pwgt2);

    obj->setFrameStyle(QFrame::Box | QFrame::Sunken);
    obj->setPalette(pal);
    obj->setLineWidth(5);
    obj->setFocus();

    QSplitter *splitHorisontal = new QSplitter();
    splitHorisontal->addWidget(pwgt1);
    splitHorisontal->addWidget(pwgt2);

    QSplitter *splitVertical = new QSplitter(Qt::Vertical);
    splitVertical->addWidget(splitHorisontal);
    splitVertical->addWidget(obj);

    QHBoxLayout *layout = new QHBoxLayout(form);
    layout->addWidget(bar);
    layout->addWidget(splitVertical);
    //layout->addWidget(pwgt2);

    QWidget::connect(bar,SIGNAL(sliderMoved(int)),form,SLOT(showNormal()));
    QWidget::connect(bar,SIGNAL(sliderPressed()),form,SLOT(showFullScreen()));
    form->setLayout(layout);
    form->show();
    return app.exec();
}
