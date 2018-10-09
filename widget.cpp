#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QtDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


int Widget::getLedPin() const
{
    return ledPin;
}


void Widget::on_led1RadioButton_clicked()
{
    ledPin = 1016;
}

void Widget::on_led2RadioButton_clicked()
{
    ledPin = 1017;
}

void Widget::on_led3RadioButton_clicked()
{
     ledPin = 1018;
}

void Widget::on_led4RadioButton_clicked()
{
     ledPin = 1019;
}


void Widget::on_onButton_clicked()
{
    qDebug()<<"ON Command";

    int pin = ledPin;
    enum direction {In,Out,Err};

    // accessing the Gpio files and turn the leds on
    QString valueString =
            QString("/sys/class/gpio/gpio%1/value").arg(pin);
    QString directionString =
            QString("/sys/class/gpio/gpio%1/direction").arg(pin);
    // accessing the Gpio files and turn the leds on
    FILE * fp;
    fp = fopen(valueString.toLatin1(),"rb+");
    fwrite("1", sizeof(char),4,fp);
    //rewind(fp);

    fclose(fp);
}

void Widget::on_offButton_clicked()
{
    qDebug()<<"OFF Command";

    int pin = ledPin;
    enum direction {In,Out,Err};

    // accessing the Gpio files and turn the leds on
    QString valueString =
            QString("/sys/class/gpio/gpio%1/value").arg(pin);
    QString directionString =
            QString("/sys/class/gpio/gpio%1/direction").arg(pin);
    // accessing the Gpio files and turn the leds on
    FILE * fp;
    fp = fopen(valueString.toLatin1(),"rb+");
    fwrite("0", sizeof(char),4,fp);
    //rewind(fp);

    fclose(fp);
}
