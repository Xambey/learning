#ifndef MYVIEW_H
#define MYVIEW_H
#include <QGraphicsView>
#include <QWheelEvent>
#include <QTimerEvent>
#include <QBasicTimer>
#include <QWidget>
#include <QLineEdit>
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
#include <QtGui>
#include <QComboBox>
#include <QStringList>
#include <QTableWidget>
#include <QToolBox>
#include <QVariant>
#include <QAbstractItemModel>
#include <QTreeView>
#include <QListView>
#include <QItemDelegate>
#include <iostream>
#include <QStandardItemModel>
#include <QtGui>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

class MyView: public QGraphicsView{
    Q_OBJECT
public:
    MyView(QGraphicsScene* pScene)
        : QGraphicsView(pScene)
    {
        (new QBasicTimer())->start(1000/30, this);


        //        QLabel* line = new  QLabel;
        //        line->setGeometry(0,-50,200,50);
        //        line->setText("llssald");

        //        QVBoxLayout lay;
        //        QPushButton *b1 = new QPushButton("&1");
        //        QPushButton *b2 = new QPushButton("&2");
        //        QPushButton *b3 = new QPushButton("&3");
        //        QPushButton *b4 = new QPushButton("&4");
        //        QPushButton *b5 = new QPushButton("&5");
        //        QPushButton *b6 = new QPushButton("&6");
        //        QPushButton *b7 = new QPushButton("&7");
        //        QPushButton *b8 = new QPushButton("&8");
        //        QPushButton *b9 = new QPushButton("&9");
        //        QPushButton *b0 = new QPushButton("&0");

        //        lay.addWidget(line);
        //        lay.addWidget(b0);
        //        lay.addWidget(b1);
        //        lay.addWidget(b2);
        //        lay.addWidget(b3);
        //        lay.addWidget(b4);
        //        lay.addWidget(b5);
        //        lay.addWidget(b6);
        //        lay.addWidget(b7);
        //        lay.addWidget(b8);
        //        lay.addWidget(b9);



        //        QObject::connect(b1, SIGNAL(clicked(bool)),line, SLOT(setText(QString)));
        //        QObject::connect(b2, SIGNAL(clicked()),line, SLOT(setText(QString)));
        //        QObject::connect(b3, SIGNAL(clicked()),line, SLOT(setText(QString)));
        //        QObject::connect(b4, SIGNAL(clicked()),line, SLOT(setText(QString)));
        //        QObject::connect(b5, SIGNAL(clicked()),line, SLOT(setText(QString)));
        //        QObject::connect(b6, SIGNAL(clicked()),line, SLOT(setText(QString)));
        //        QObject::connect(b7, SIGNAL(clicked()),line, SLOT(setText(QString)));
        //        QObject::connect(b8, SIGNAL(clicked()),line, SLOT(setText(QString)));
        //        QObject::connect(b9, SIGNAL(clicked()),line, SLOT(setText(QString)));
        //        QObject::connect(b0, SIGNAL(clicked()),line, SLOT(setText(QString)));

        //pwgt.setLayout(&lay);
        //pScene.addWidget(&pwgt);
        // setViewport(&pwgt);
        //        SetLayout(lay);
        // setLayout(&lay);
        //pwgt.setLayout(&lay);
        //pwgt.setRenderHint(QPainter::Antialiasing, true);
    }

protected:
    void wheelEvent(QWheelEvent*pe){
        rotate(-20);

    }
    void timerEvent(QTimerEvent *){
        rotate(-1);
        translate(-20,40);
    }
public slots:

    void slotZoomIn()
    {
    scale(1.1, 1.1);
    }
    void slotZoomOut()
    {
    scale(1 / 1.1, 1 / 1.1);
    }
    void slotRotateLeft()
    {
    rotate(-5);
    }
    void slotRotateRight()
    {
    rotate(5);
    }
    void updateLabel(QLabel& wgt, QPushButton* n){
        wgt.setText(n->text());
    }
signals:
    void clicked(QLineEdit&);
};

#endif // MYVIEW_H
