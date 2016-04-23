#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "gui.h"

class Controller: public QWidget
{
    Q_OBJECT
private:
    QGridLayout layer;
    QPushButton btnReset;
    QWidget result;
    QSlider red;
    QScrollBar green;
    QSlider blue;
    QDial dial;
    bool block;

public:
    Controller()
    {
        result.setAutoFillBackground(1);
        result.setMinimumSize(64, 64);
        red.setMaximum(255);
        green.setMaximum(255);
        blue.setMaximum(255);
        dial.setRange(0, 255);
        btnReset.setText("Сброс");

        layer.addWidget(&result, 0, 0, 1, 3);
        layer.addWidget(new QLabel("<center><font color=red>R</font></center>"), 1, 0);
        layer.addWidget(new QLabel("<center><font color=green>G</font></center>"), 1, 1);
        layer.addWidget(new QLabel("<center><font color=blue>B</font></center>"), 1, 2);
        layer.addWidget(&red, 2, 0);
        layer.addWidget(&green, 2, 1);
        layer.addWidget(&blue, 2, 2);
        layer.addWidget(new QLabel("<center>Black</center>"), 3, 0, 1, 3);
        layer.addWidget(&dial, 4, 0, 1, 3);
        layer.addWidget(&btnReset, 5, 0, 1, 3);

        QWidget::connect(&red,      SIGNAL(valueChanged(int)),  this, SLOT(updateColor()));
        QWidget::connect(&green,    SIGNAL(valueChanged(int)),  this, SLOT(updateColor()));
        QWidget::connect(&blue,     SIGNAL(valueChanged(int)),  this, SLOT(updateColor()));
        QWidget::connect(&dial,     SIGNAL(valueChanged(int)),  this, SLOT(setIntensiv(int)));
        QWidget::connect(&btnReset, SIGNAL(clicked(bool)),      this, SLOT(reset()));

        setLayout(&layer);
        block = false;
        reset();
    }

private slots:
    void reset()
    {
        red.setValue(255);
        green.setValue(255-228);
        blue.setValue(30);
    }

    void setIntensiv(int value)
    {
        if(block)
            return;
        block = true;

        red.setValue(value);
        green.setValue(255-value);
        blue.setValue(value);
        block = false;
        updateColor();
    }

    void updateColor()
    {
        if(block)
            return;
        block = true;

        QPalette pl;
        int r = red.value(),
            g = 255-green.value(),
            b = blue.value();

        dial.setValue((r+g+b)/3);
        pl.setColor(QPalette::Background, QColor(r,g,b));
        result.setPalette(pl);
        block = false;
    }
};

#endif // CONTROLLER_H
