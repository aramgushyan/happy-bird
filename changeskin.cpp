#include "changeskin.h"
#include "ui_changeskin.h"

changeskin::changeskin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeskin)
{
    ui->setupUi(this);
    QPixmap background(":/sky.png"); // Путь к вашему изображению
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);


}

changeskin::~changeskin()
{
    delete ui;
}




void changeskin::on_radioButton_clicked()
{
    emit change();
}

