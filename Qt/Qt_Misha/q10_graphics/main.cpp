#include "QApplication"
#include "qDebug"
#include "QLayout"
#include "QtWidgets"
#include "myview.h"
#include "qmath.h"

class SimpleItem : public QGraphicsItem
{
    enum
    {
        nPenWidth = 3
    };

public:
    virtual QRectF boundingRect() const
    {
        QPointF pos(-10 - nPenWidth, -10 - nPenWidth);
        QSizeF size(20 + nPenWidth * 2, 20 + nPenWidth * 2);

        return QRectF(pos, size);
    }

    virtual void paint(QPainter* ppainter, const QStyleOptionGraphicsItem*, QWidget*)
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

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget    wgt;
    QGraphicsScene scene(QRectF(-100, -100, 640, 480));
    MyView* pView = new MyView(&scene);
    QPushButton* pcmdZoomIn = new QPushButton("&Zoom In");
    QPushButton* pcmdZoomOut = new QPushButton("Z&oom Out");
    QPushButton* pcmdRotateLeft = new QPushButton("&Rotate Left");
    QPushButton* pcmdRotateRight = new QPushButton("Ro&tate Right");

    pView->setRenderHint(QPainter::Antialiasing, true);

    QGraphicsPixmapItem* pPixmapItem = scene.addPixmap(QPixmap("aBYKS749x88.jpg"));
    pPixmapItem->setFlags(QGraphicsItem::ItemIsMovable);

    for(int i = 0; i < 20; i++)
    {
        SimpleItem* pSimpleItem = new SimpleItem;
        scene.addItem(pSimpleItem);
        pSimpleItem->setPos(i*30, 0);
        pSimpleItem->setFlags(QGraphicsItem::ItemIsMovable);
        pSimpleItem->setParentItem(pPixmapItem);
    }

    QObject::connect(pcmdZoomIn,     SIGNAL(clicked()),  pView, SLOT(slotZoomIn()));
    QObject::connect(pcmdZoomOut,    SIGNAL(clicked()),  pView, SLOT(slotZoomOut()));
    QObject::connect(pcmdRotateLeft, SIGNAL(clicked()),  pView, SLOT(slotRotateLeft()));
    QObject::connect(pcmdRotateRight,SIGNAL(clicked()),  pView, SLOT(slotRotateRight()));

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pView);
    pvbxLayout->addWidget(pcmdZoomIn);
    pvbxLayout->addWidget(pcmdZoomOut);
    pvbxLayout->addWidget(pcmdRotateLeft);
    pvbxLayout->addWidget(pcmdRotateRight);
    wgt.setLayout(pvbxLayout);
    wgt.show();

    return app.exec();
}
