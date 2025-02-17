#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <QWidget>
#include "scene.h"
#include "changeskin.h"
namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::menu *ui;
    Scene *scen;
};

#endif // MENU_H
