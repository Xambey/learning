#include "spinboxdelegate.h"


#include <QSpinBox>
#include <QComboBox>
#include <cstdlib>
#include <ctime>
#include <QtWidgets>

SpinBoxDelegate::SpinBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *SpinBoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &index ) const
{   srand(time(0));
    if(index.column() == 2){
        QComboBox *box = new QComboBox(parent);
        QStringList str;
        QString strpart("8-");
        for(unsigned int i(0); i < 10; i++){
            str << strpart +QString::number(rand() %888 + 111) + "-"+QString::number(rand() %888 + 111)+"-" + QString::number(rand() %88+11)+"-"+ QString::number(rand() %88+11);
        }
        box->addItems(str);
        box->setFrame(false);
        return box;
    }
    QLineEdit *editor = new QLineEdit(parent);
    editor->setFrame(false);
    //editor->setMinimum(0);
    //editor->setMaximum(1000);

    return editor;
}
//! [1]

//! [2]
void SpinBoxDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();
    if(index.column() == 2){
        QComboBox *bo = static_cast<QComboBox*>(editor);
        bo->currentText().toInt();
    }
    else{
        QLineEdit *spinBox = static_cast<QLineEdit*>(editor);
        QString old_value = index.model()->data(index, Qt::EditRole).toString();
//        if(!value){
//            spinBox->setText(QString::number(value));
//        }

            spinBox->setText(old_value);
        //spinBox->setValue(value);
    }
}
//! [2]

//! [3]
void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    if(index.column() == 2){
        QComboBox *box = static_cast<QComboBox*>(editor);
        box->currentText().toInt();
        int value = box->currentText().toInt();
//        box->setCurrentText(QString::number(value));
        model->setData(index, value, Qt::EditRole);
    }
    else{
        QLineEdit *spinBox = static_cast<QLineEdit*>(editor);
        //spinBox->interpretText();
        QString value = spinBox->text();

        model->setData(index, value, Qt::EditRole);
    }
}
//! [3]

//! [4]
void SpinBoxDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
//! [4]
