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


class SimpleItem : public QGraphicsItem {
private:
    enum {nPenWidth = 3};
public:

    virtual QRectF boundingRect() const
{
    QPointF ptPosition(-10 - nPenWidth, -10 - nPenWidth);
    QSizeF size(20 + nPenWidth * 2, 20 + nPenWidth * 2);
    return QRectF(ptPosition, size);
}
    virtual void paint(QPainter* ppainter,
    const QStyleOptionGraphicsItem*,
    QWidget*
    )
    {
        ppainter->save();
        ppainter->setPen(QPen(Qt::blue, nPenWidth));
        ppainter->drawEllipse(-10, -10, 20, 20);
        ppainter->restore();
    }
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* pe)
    {
        QApplication::setOverrideCursor(Qt::PointingHandCursor);
        QGraphicsItem::mousePressEvent(pe);
    }
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* pe)
    {
        QApplication::restoreOverrideCursor();
        QGraphicsItem::mouseReleaseEvent(pe);
    }

    };
