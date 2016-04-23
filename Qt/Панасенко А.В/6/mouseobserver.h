#ifndef _MouseObserver_h_
#define _MouseObserver_h_
#include <QtGui>
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
#include <QKeyEvent>
#include <QTimerEvent>
#include <ctime>
#include <QWheelEvent>
// ======================================================================
class MouseObserver : public QLabel{
    public:
        float r, g, b;
        QBasicTimer timer;
        MouseObserver(QWidget* pwgt = 0);
    protected:
        virtual void mousePressEvent (QMouseEvent* pe);
        virtual void mouseReleaseEvent(QMouseEvent* pe);
        virtual void mouseMoveEvent (QMouseEvent* pe);
        void dumpEvent (QMouseEvent* pe, const QString& strMessage);
        QString modifiersInfo (QMouseEvent* pe );
        QString buttonsInfo (QMouseEvent* pe );

        virtual void keyPressEvent(QKeyEvent*);
        virtual void timerEvent(QTimerEvent*);
        virtual void wheelEvent(QWheelEvent*);

};
#endif //_MouseObserver_h_
