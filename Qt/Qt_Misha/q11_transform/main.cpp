#include <QApplication>
#include <QtWidgets>
#include "controller.h"
#include "proxy.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.setStickyFocus(true);

    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            proxy* p = new proxy(0, Qt::Window);
            p->setWidget(new Controller());

            QRectF rect = p->boundingRect();

            p->setPos(x * rect.width() * 1.05, y * rect.height() * 1.05);
            p->setCacheMode(QGraphicsItem::DeviceCoordinateCache);

            scene.addItem(p);
        }
    }
    scene.setSceneRect(scene.itemsBoundingRect());

    QGraphicsView view(&scene);
    view.setRenderHints(view.renderHints());
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.show();
    view.setWindowTitle("More controllers for God controllers!");

    return a.exec();
}
