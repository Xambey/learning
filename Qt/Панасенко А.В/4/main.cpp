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
#include <QComboBox>
#include <QStringList>
#include <QTableWidget>
#include <QToolBox>

int main (int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget wgt;
    QStringList list;
    list << "1" << "2" << "3" <<"4";

    QTableWidget mytable(4, 5);
    QTableWidgetItem* pw = NULL;
    mytable.setHorizontalHeaderLabels(list);
    mytable.setVerticalHeaderLabels(list);

    QBrush br(Qt::BackgroundColorRole, Qt::NoBrush);


    for(int i(0);i < 4; i++)
        for(int j(0); j < 5; j++){
            pw = new QTableWidgetItem(QString("%10, %11").arg(i).arg(j));
            pw->setBackground(br);
            //pw->setBackgroundColor(QColor::black());
            //pw->setBackgroundColor(&c);
            mytable.setItem(i, j, pw);
        }
    QComboBox* box = new QComboBox;
    box->addItems(list);
    QString str ("111");
    QTabWidget tab;
//    foreach(QString str, list){
//        tab.addTab(new QLabel(str, &tab), str);
//    }
    QLabel* la = new QLabel(str, &tab);
    tab.addTab(la, QString("1"));
    tab.addTab(new QLineEdit, str);
    QToolBox * gg = new QToolBox;
    gg->addItem(new QLineEdit, QString("222"));


    QLabel* plblDisplay = new QLabel;

    plblDisplay->setFrameStyle(QFrame::Box | QFrame::Raised);
    plblDisplay->setLineWidth(5);
    plblDisplay->setFixedHeight(50);

    QLabel* plblText = new QLabel("&Text:");

    QLineEdit* text = new QLineEdit;

    text->setInputMask("0-(000)-000-00-00");
    QLineEdit* text3 = new QLineEdit;

    text3->setInputMask("0-(000)-000-00-00");
    tab.addTab(text3, QString("0-(000)-000-00-00"));
    QWidget::connect(tab.widget(0), SIGNAL(objectNameChanged(QString)),tab.widget(2), SLOT(setEnabled(bool)));




    QTextEdit* text2 = new QTextEdit;
    text2->setHtml("<html><div><center><h3>I wrote the HTML</h3></center></div></html>");
    MyHighlighter* pHighlighter = new MyHighlighter(text2->document());

    QLineEdit* ptxt = new QLineEdit;
    plblText->setBuddy(ptxt);

    QObject::connect(ptxt, SIGNAL(textChanged(const QString&)),
    plblDisplay, SLOT(setText(const QString&))
    );

    QObject::connect(text, SIGNAL(textChanged(const QString&)),
    plblDisplay, SLOT(setText(const QString&))
    );

    QObject::connect(text2, SIGNAL(windowTitleChanged(QString)),
    plblDisplay, SLOT(setText(const QString&))
    );

    QLabel* plblPassword = new QLabel("&Password:");

    QLineEdit* ptxtPassword = new QLineEdit;

    plblPassword->setBuddy(ptxtPassword);
    ptxtPassword->setEchoMode(QLineEdit::Password);
    ptxtPassword->setValidator(new QIntValidator);

    QObject::connect(ptxtPassword, SIGNAL(textChanged(const QString&)),
    plblDisplay, SLOT(setText(const QString&))
    );
    //Layout setup
    QHBoxLayout* lay = new QHBoxLayout;
    QVBoxLayout* pvbxLayout = new QVBoxLayout;


    pvbxLayout->addWidget(plblDisplay);
    pvbxLayout->addWidget(plblText);
    pvbxLayout->addWidget(ptxt);
    pvbxLayout->addWidget(plblPassword);
    pvbxLayout->addWidget(ptxtPassword);
    pvbxLayout->addWidget(text);
    pvbxLayout->addWidget(text2);
    pvbxLayout->addWidget(box);

    lay->addLayout(pvbxLayout);

    lay->addWidget(&tab);
    lay->addWidget(&mytable);
    lay->addWidget(gg);

    wgt.setLayout(lay);
    wgt.show();
    return app.exec();
}
