#include <QApplication>
#include <QWidget>
#include <QScrollArea>
#include <QFrame>

int main(int argc, char** argv)
{
    QApplication a(argc, argv);

    QWidget* form = new QWidget();
    QWidget* container = new QWidget();
    container->setGeometry(0,0,1000,1000);

    QScrollArea* viewport = new QScrollArea(form);
    viewport->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    viewport->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    viewport->setGeometry(0,0,600,480);
    viewport->setWidget(container);

    QPalette pal;
    for(int i = 0; i < 7; i++)
    {
        QFrame* wgt = new QFrame(container);
        pal.setColor(QPalette::Background, QColor((255/7)*i,255-(255/7)*i,0));
        wgt->setPalette(pal);
        wgt->setAutoFillBackground(1);
        wgt->setGeometry(50 + i*100, 50, 80, 80*(i+1));
        wgt->setFrameStyle(i | QFrame::Sunken);
        wgt->setLineWidth(3);
    }

    form->setGeometry(100,100,600,480);
    form->show();

    return a.exec();
}
