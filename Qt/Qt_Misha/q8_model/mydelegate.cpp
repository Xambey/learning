#include "mydelegate.h"

#include <QLineEdit>
#include <QDateEdit>

mydelegate::mydelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *mydelegate::createEditor(QWidget *parent,
                                  const QStyleOptionViewItem &/* option */,
                                  const QModelIndex &index) const
{
    if(index.column () == 1){
        QDateEdit *cb = new QDateEdit(parent);
        return cb;
    }
    QLineEdit *editor = new QLineEdit(parent);
    return editor;
}

void mydelegate::setEditorData(QWidget *editor,
                               const QModelIndex &index) const
{
    QString value = index.model()->data(index, Qt::EditRole).toString();

    if(index.column () == 1){
        QDateEdit *cb = static_cast<QDateEdit*>(editor);
        cb->setCurrentSectionIndex(0);
        return;
    }

    QLineEdit *LineEdit = static_cast<QLineEdit*>(editor);
    LineEdit->setText(value);
}

void mydelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                              const QModelIndex &index) const
{
    QString value;
    if(index.column () == 1){
        QDateEdit *cb = static_cast<QDateEdit*>(editor);
        value = cb->currentSection();
    }

    else {
        QLineEdit *LineEdit = static_cast<QLineEdit*>(editor);
        LineEdit->internalWinId();
        value = LineEdit->text();
    }

    model->setData(index, value, Qt::EditRole);
}
void mydelegate::updateEditorGeometry(QWidget *editor,
                                      const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

