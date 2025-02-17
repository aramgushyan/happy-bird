#ifndef CHANGESKIN_H
#define CHANGESKIN_H

#include <QDialog>
#include <QPalette>
#include <QPixmap>
#include <QLabel>
#include "QString"
namespace Ui {
class changeskin;
}

class changeskin : public QDialog
{
    Q_OBJECT

public:
    explicit changeskin(QWidget *parent = nullptr);
    ~changeskin();
signals:
    void change();
private slots:

    void on_radioButton_clicked();


private:
    Ui::changeskin *ui;
};

#endif // CHANGESKIN_H
