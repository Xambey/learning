#ifndef MYHIGHLIGHTER_H
#define MYHIGHLIGHTER_H
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


class MyHighlighter: QSyntaxHighlighter
{
public:
    MyHighlighter(QTextDocument *parent);
    void highlightBlock(const QString& str);
signals:

public slots:
};

#endif // MYHIGHLIGHTER_H
