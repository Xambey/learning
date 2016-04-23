#include <QApplication>
#include "gui.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller* form = new Controller();
    form->move(320, 100);
    form->show();

    return a.exec();
}
