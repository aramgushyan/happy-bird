#ifndef RESTART_H
#define RESTART_H

#include <QDialog>
#include "widget.h"
#include "menu.h"
namespace Ui {
class restart;
}

class restart : public QDialog
{
    Q_OBJECT

public:
    explicit restart(QWidget *parent = nullptr);
    ~restart();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::restart *ui;
};

#endif // RESTART_H
