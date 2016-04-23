#include "progress.h"
#include <QLabel>
#include <QtGui>
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>
#include <QLineEdit>
#include <QSpinBox>
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
#include <QWidget>

Progress::Progress(QWidget *target, QAbstractSlider *r, QAbstractSlider *g, QAbstractSlider *b)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->target = target;

    connect(r,          SIGNAL(sliderMoved(int)),this, SLOT(ChangeColor()));
    connect(g,          SIGNAL(sliderMoved(int)),this, SLOT(ChangeColor()));
    connect(b,          SIGNAL(sliderMoved(int)),this, SLOT(ChangeColor()));


}

void Progress::ChangeColor(){
    QPalette pal;
    pal.setColor(QPalette::Background, QColor(r->value(), g->value(), b->value()));
    target->setPalette(pal);
}

