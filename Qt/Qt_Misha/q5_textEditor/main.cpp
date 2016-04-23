#include <QtWidgets>
#include "myhighlighter.h"

int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    QTextEdit* form = new QTextEdit();

    form->setHtml("<html><div><center><h3>Hollo world!</h3></center></div></html>");
    new MyHighlighter(form->document());

    form->show();

    return app.exec();
}
