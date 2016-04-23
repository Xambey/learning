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
#include <QSyntaxHighlighter>
#include "myhighlighter.h"
#include <QtGui>


MyHighlighter::MyHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
}

void MyHighlighter::highlightBlock(const QString& str)
{
    bool f = false;
    bool pr = false;
    for (int i = 0; i < str.length(); ++i) {
        if (str.at(i).isNumber()) {
            setFormat(i, 1, Qt::red);
        }
        if(str.at(i) == '"'){
            f = !f;
            setFormat(i, 1, Qt::blue);
            i++;
        }
        if(f){
            setFormat(i, 1, Qt::green);
        }
    }
}
