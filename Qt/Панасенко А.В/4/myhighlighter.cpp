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
    int c = 0;
    for (int i = 0; i < str.length(); ++i) {
        if(str.at(i) == '1'){

            if(c < 3){
                setFormat(i, 1, Qt::blue);
            }
            c++;
            continue;
        }

        if (str.at(i).isNumber() && str.at(i) != '1') {
            setFormat(i, 1, Qt::red);
            c = 0;
        }
        if(str.at(i) == '"'){
            f = !f;
            setFormat(i, 1, Qt::blue);
            i++;
            c = 0;
        }
        if(f){
            setFormat(i, 1, Qt::green);
            c = 0;
        }

    }
}
