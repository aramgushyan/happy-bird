#include "menu.h"
#include "ui_menu.h"
#include "widget.h"
menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);

}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
    hide();
    Widget* fwindow;
    fwindow = new Widget;
    fwindow->showMaximized();
    this->close();
}


void menu::on_pushButton_3_clicked()
{
    changeskin* fwindow;
    fwindow = new changeskin;
    fwindow->showNormal();
}

