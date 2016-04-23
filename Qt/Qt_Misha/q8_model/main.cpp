#include <QApplication>
#include <QDirModel>
#include <QTreeView>
#include <QStandardItemModel>
#include <QStringlist>
#include <QCalendarWidget>
#include "mydelegate.h"
#include <QtWidgets>
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    // QDirModel model;
    // QTreeView treeView;
    // treeView.setModel(&model);
    // treeView.show();


    //    QStandardItemModel model(5, 3);
    //    for (int nTopRow = 0; nTopRow < 5; ++nTopRow) {
    //        QModelIndex index = model.index(nTopRow, 0);
    //        model.setData(index, "item" + QString::number(nTopRow + 1));
    //        model.insertRows(0, 4, index);
    //        model.insertColumns(0, 3, index);
    //        for (int nRow = 0; nRow < 4; ++nRow) {
    //            for (int nCol = 0; nCol < 3; ++nCol) {
    //                QString strPos = QString("%1,%2").arg(nRow).arg(nCol);
    //                model.setData(model.index(nRow, nCol, index), strPos);
    //            }
    //        }
    //    }
    //    QTreeView treeView;
    //    treeView.setModel(&model);
    //    treeView.show();

    QStringList FIO;
    FIO << "Ильдар" << "Андрей" << "Миша" << "Саша";
    QStringList year;
    year << "1997" << "1996" << "1996" << "1997";



    QStandardItemModel model(5, 3);
    model.setHorizontalHeaderLabels(QStringList() << "Студент" << "Год рождения" << "Календарь");
    for (int nTopRow = 0; nTopRow < 5; ++nTopRow) {
        QModelIndex index = model.index(nTopRow, 0);
        model.setData(index, "Курс " + QString::number(nTopRow + 1));
        model.insertRows(0, 4, index);
        model.insertColumns(0, 1, index);
        for (int a = 0; a < 4; ++a) {
            QModelIndex index2 = model.index(a, 0, index);
            model.setData(index2, "ИВБ-0" + QString::number(a + 1) + "-14");
            model.insertRows(0, 4, index2);
            model.insertColumns(0, 2, index2);
            for (int b = 0; b < 4; ++b) {
                model.setData(model.index(b, 0, index2),FIO [b]);
                model.setData(model.index(b, 1, index2),year [b]);
//                model.setData(model.index(b, 3, index2),);
            }
        }
    }
    QComboBox box;
    QTreeView treeView;
    treeView.setModel(&model);
    treeView.setItemDelegate(new mydelegate());
    treeView.show();

    box.setModel(&model);
    box.setItemDelegate(new mydelegate());
    box.show();



    return app.exec();
}
