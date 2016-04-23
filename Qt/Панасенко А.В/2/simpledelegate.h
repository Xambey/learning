#ifndef SIMPLEDELEGATE_H
#define SIMPLEDELEGATE_H
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
#include <QItemDelegate>

class SimpleDelegate : public QItemDelegate {
    Q_OBJECT
public:
    SimpleDelegate(QObject* pobj = 0) : QItemDelegate(pobj)
    {

    }
    void paint(QPainter* pPainter,const QStyleOptionViewItem& option,
        const QModelIndex& index) const {

        if (option.state & QStyle::State_MouseOver) {
            QRect rect = option.rect;

            QLinearGradient gradient(0, 0, rect.width(),rect.height());

            gradient.setColorAt(0, Qt::white);
            gradient.setColorAt(0.5, Qt::blue);
            gradient.setColorAt(1, Qt::green);

            pPainter->setBrush(gradient);
            pPainter->drawRect(rect);
        }
            QItemDelegate::paint(pPainter, option, index);
        }
};

#endif // SIMPLEDELEGATE_H
