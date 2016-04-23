#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QGroupBox>
#include <QRadioButton>
#include <QGridLayout>
#include <QSplitter>
#include <QProgressBar>
#include <QPushButton>
#include <QSpinBox>
#include <QCheckBox>

int main(int argc, char** argv)
{
    QApplication a(argc, argv);

    QWidget* form = new QWidget();
    QVBoxLayout layer;

    QLineEdit editText;
    editText.setInputMask("000.000.000.000");
    QSpinBox editCount;
    editCount.setValue(10);

    QGroupBox groop,groopLeft,groopRight;
    QGridLayout rbGrid;

    QGridLayout groopLayer;
    groopLayer.addWidget(new QRadioButton("Раз"),0,0);
    groopLayer.addWidget(new QRadioButton("Два"),1,0);
    groopLayer.addWidget(new QRadioButton("Три"),0,1);
    groopLayer.addWidget(new QRadioButton("Четыре"),1,1);
    groopLeft.setTitle("Текст");
    groopLeft.setLayout(&groopLayer);
    rbGrid.addWidget(&groopLeft, 0, 0);

    QVBoxLayout groopLayer2;
    groopLayer2.addWidget(new QRadioButton("228"));
    groopLayer2.addWidget(new QRadioButton("322"));
    groopLayer2.addWidget(new QRadioButton("223"));
    groopRight.setCheckable(1);
    groopRight.setTitle("Solo?");
    groopRight.setLayout(&groopLayer2);
    rbGrid.addWidget(&groopRight, 0, 1);

    groop.setTitle("Радиокнопки");
    groop.setLayout(&rbGrid);

    layer.addWidget(new QLabel("Введите IP адресс:"));
    layer.addWidget(&editText);
    layer.addWidget(new QLabel("Введите число:"));
    layer.addWidget(&editCount);
    layer.addWidget(&groop);

    form->setLayout(&layer);
    form->setGeometry(100,100,265,265);
    form->show();

    return a.exec();
}
