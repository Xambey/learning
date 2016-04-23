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
#include <QAbstractItemModel>
#include <QTreeView>
#include <QListView>
#include "simpledelegate.h"

int main(int argc, char** argv){
    QApplication app(argc, argv);
    QWidget wgt;
    QStringListModel model;

    model.setStringList(QStringList() << "Item1" << "Item2" << "Item3");



    QTreeView* pTreeView = new QTreeView;

    pTreeView->setModel(&model);
    pTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QListView* pListView = new QListView;

    pListView->setModel(&model);

    QTableView* pTableView = new QTableView;

    pTableView->setModel(&model);

    QItemSelectionModel selection(&model);

    pTreeView->setSelectionModel(&selection);
    pListView->setSelectionModel(&selection);
    pTableView->setSelectionModel(&selection);

    QStringList str;
    str << "1"<< "2"<<"3";

    QHBoxLayout* phbxLayout = new QHBoxLayout;


    QListView listView;
    listView.setModel(&model);
    listView.setit
    listView.setItemDelegate(new SimpleDelegate(&listView));
    listView.viewport()->setAttribute(Qt::WA_Hover);
    phbxLayout->addWidget(&listView);


    phbxLayout->addWidget(pTreeView);
    phbxLayout->addWidget(pListView);
    phbxLayout->addWidget(pTableView);



    QListView listView;
    listView.setModel(&model);
    listView.setItemDelegate(new SimpleDelegate(&listView));
    listView.viewport()->setAttribute(Qt::WA_Hover);
    phbxLayout->addWidget(&listView);

    wgt.setLayout(phbxLayout);
    wgt.show();
    return app.exec();
}
