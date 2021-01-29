#include "dialogconnect.h"
#include "ui_dialogconnect.h"

DialogConnect::DialogConnect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnect)
{
    ui->setupUi(this);
}

DialogConnect::~DialogConnect()
{
    delete ui;
}

int DialogConnect::getPort()
{
    return this->ui->port->displayText().toInt();
}

QString DialogConnect::getHost()
{
    return this->ui->host->displayText();
}



void DialogConnect::on_host_textChanged(const QString &arg1)
{
    this->ui->uri->setText("mongodb://" + arg1 + ":" + this->ui->port->displayText());
}

void DialogConnect::on_port_textChanged(const QString &arg1)
{
    this->ui->uri->setText("mongodb://" + this->ui->host->displayText() + ":" + arg1);
}
