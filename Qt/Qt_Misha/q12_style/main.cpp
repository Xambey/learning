#include <QtWidgets>
#include "customstyle.h"

int main (int argc, char** argv)
{
    QApplication app(argc, argv);
    app.setStyle(new CustomStyle());

    QWidget wgt;

    QPushButton* pcmdA = new QPushButton ("Button1");
    QPushButton* pcmdB = new QPushButton ("Button2");
    QPushButton* pcmdC = new QPushButton ("Button3");

    pcmdA->setMinimumHeight(64);
    pcmdB->setMinimumHeight(64);
    pcmdC->setMinimumHeight(64);

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pcmdA);
    pvbxLayout->addWidget(pcmdB);
    pvbxLayout->addWidget(pcmdC);

    wgt.setLayout(pvbxLayout);
    wgt.setGeometry(100, 200, 220, 256);
    wgt.show();

    return app.exec();
}
