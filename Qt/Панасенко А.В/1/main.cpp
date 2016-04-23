#include <QLabel>
#include <QtGui>
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>
#include <QLineEdit>
#include <QSpinBox>
#include "progress.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QCheckBox>
#include <QGroupBox>
#include<QRadioButton>
#include <QWidget>
#include <QGridLayout>
#include <QAbstractSlider>
#include <QDial>
#include <QSlider>
#include <cstdlib>
#include <ctime>
#include <QBrush>
#include <QProgressBar>

int main(int argc, char**argv){
    QApplication app(argc, argv);

    QWidget* wgt = new QWidget;

    QProgressBar* bar1 = new QProgressBar;
    QProgressBar* bar2 = new QProgressBar;
    QProgressBar* bar3 = new QProgressBar;

    QLabel* lab1 = new QLabel;
    QLabel* lab2 = new QLabel;
    QLabel* lab3 = new QLabel;

    bar1->setOrientation(Qt::Vertical);
    bar2->setOrientation(Qt::Vertical);
    bar3->setOrientation(Qt::Vertical);

    bar1->setRange(0, 255);
    bar2->setRange(0, 255);
    bar3->setRange(0, 255);


    wgt->resize(600, 600);
    QWidget* wgt1 = new QWidget;
    wgt1->setAutoFillBackground(1);
    wgt1->setMinimumSize(400,200);
    QPalette pal;
    pal.setColor(QPalette::Background, QColor(0, 0, 0));
    wgt1->setPalette(pal);



    QSplitter* splitter1 = new QSplitter(Qt::Vertical);
    QSplitter* splitter2 = new QSplitter(Qt::Horizontal);

    QSlider* slider1 = new QSlider(Qt::Vertical);
    QSlider* slider2 = new QSlider(Qt::Vertical);
    QSlider* slider3 = new QSlider(Qt::Vertical);

    QObject::connect(slider1,          SIGNAL(sliderMoved(int)),bar1, SLOT(setValue(int)));
    QObject::connect(slider2,          SIGNAL(sliderMoved(int)),bar2, SLOT(setValue(int)));
    QObject::connect(slider3,          SIGNAL(sliderMoved(int)),bar3, SLOT(setValue(int)));

    QObject::connect(slider1,          SIGNAL(sliderMoved(int)),lab1, SLOT(setNum(int)));
    QObject::connect(slider2,          SIGNAL(sliderMoved(int)),lab2, SLOT(setNum(int)));
    QObject::connect(slider3,          SIGNAL(sliderMoved(int)),lab3, SLOT(setNum(int)));

    new Progress(wgt1, slider1, slider2, slider3);

    slider1->setRange(0, 255);
    slider2->setRange(0, 255);
    slider3->setRange(0, 255);

    slider1->setValue(0);
    slider2->setValue(0);
    slider3->setValue(0);

    slider1->setTickPosition(QSlider::TicksAbove);
    slider2->setTickPosition(QSlider::TicksAbove);
    slider3->setTickPosition(QSlider::TicksAbove);

    QVBoxLayout* layout = new QVBoxLayout;
    QHBoxLayout* layout1 = new QHBoxLayout;
    QHBoxLayout* layout2 = new QHBoxLayout;
    QHBoxLayout* layout3 = new QHBoxLayout;

    layout3->addWidget(lab1);
    layout3->addWidget(lab2);
    layout3->addWidget(lab3);

    layout1->addWidget(wgt1);
    layout2->addWidget(bar1);
    layout2->addWidget(slider1);
    //layout2->addWidget(splitter1);
    layout2->addWidget(bar2);
    layout2->addWidget(slider2);
    layout2->addWidget(bar3);
    //layout2->addWidget(splitter1);
    layout2->addWidget(slider3);

    layout->addLayout(layout1);
    layout->addWidget(splitter2);
    layout->addLayout(layout2);
    layout->addWidget(splitter2);
    layout->addLayout(layout3);

    wgt->setLayout(layout);
    wgt->show();
    return app.exec();
}
