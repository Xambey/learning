#include <QtGui>
#include <QApplication>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QTableView>
#include <QLayout>
#include <QComboBox>
#include <QTreeView>
#include <QTableWidget>
#include <iostream>
#include <cstdlib>
#include <QLabel>
#include "spinboxdelegate.h"
#include <QComboBox>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    //QVBoxLayout lay;
    //QWidget wgt;
    //lay.addWidget(lbl);

    QStringList list;
    list << "1" << "2" << "3" << "4";

    QStandardItemModel model(3, 3);
    QStringList on;
    on << "1" << "2" << "3";
    QStringList str21;
    str21 << "Петя"<< "199"<<"8-916-555-31-4";
    model.setHorizontalHeaderLabels(QStringList() << "Имя"<< "Дата" << "телефон" );
    for(int top_row = 0; top_row < 3;top_row++){
        QModelIndex index1 = model.index(top_row, 0);

        QString str1 = QString("ivb-3-1"+QString::number(top_row+3));

        //QObject::connect(lbl, SIGNAL(objectNameChanged(QString)),&str1,SLOT),

        model.setData(index1,str1);
        model.insertRows(0, 3, index1);
        model.insertColumns(0, 1, index1);



        for(int row = 0; row < 3; row++){
            QModelIndex index2 = model.index(row, 0, index1);
            QString str2 = QString("student"+QString::number(row+1));
            model.setData(index2, str2);
            model.insertRows(0, 1, index2);
            model.insertColumns(0, 3, index2);
            for(int ro = 0; ro < 3; ++ro){
                QModelIndex index3 = model.index(0, ro, index2);
                model.setData(index3, str21[ro]+QString::number(row+1));
            }
        }
    }

    QTreeView treeView;
    treeView.setItemDelegate(new SpinBoxDelegate());
    treeView.setModel(&model);
    treeView.resize(600,600);
    treeView.show();

    return app.exec();
}
