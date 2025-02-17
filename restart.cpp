#include "restart.h"
#include "ui_restart.h"

restart::restart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::restart)
{
    ui->setupUi(this);
}

restart::~restart()
{
    delete ui;
}

void restart::on_pushButton_clicked()
{
    hide();
    Widget* fwindow;
    fwindow = new Widget;
    fwindow->showMaximized();
    this->close();
}


void restart::on_pushButton_2_clicked()
{
    hide();
    menu* wind;
    wind = new menu;
    wind->showMaximized();
    this->close();
}

