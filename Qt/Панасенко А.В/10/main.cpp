#include <QtWidgets>
#include "style.h"

int main (int argc, char** argv)
{
    QApplication app(argc, argv);
    app.setStyle(new style());

    QWidget wgt;

    QPushButton* pcmdA = new QPushButton ("Button1");
    QPushButton* pcmdB = new QPushButton ("Button2");
    QSlider* sld = new QSlider;
    QPushButton* pcmdC = new QPushButton ("Button3");


    sld->setMinimumHeight(64);
    pcmdA->setMinimumHeight(64);
    pcmdB->setMinimumHeight(64);
    pcmdC->setMinimumHeight(64);

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pcmdA);
    pvbxLayout->addWidget(pcmdB);
    pvbxLayout->addWidget(pcmdC);
    pvbxLayout->addWidget(sld);

    wgt.setLayout(pvbxLayout);
    wgt.setGeometry(100, 200, 220, 256);
    wgt.show();

    return app.exec();
}
