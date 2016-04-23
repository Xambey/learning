#ifndef PROGRESS_H
#define PROGRESS_H

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
#include <QObject>

class Progress : QObject
{
    Q_OBJECT
public:
    explicit Progress(QWidget *target, QAbstractSlider *r, QAbstractSlider *g, QAbstractSlider *b);
QWidget* target;
QAbstractSlider *r, *g, *b;
public slots:
    void ChangeColor();
};

#endif // PROGRESS_H
