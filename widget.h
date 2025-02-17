#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "scene.h"
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimedia/QMediaPlayer>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    Scene *scene;
    QMediaPlaylist *m_list;
    QMediaPlayer * m_play;
    bool flag = false;


    // QWidget interface
protected:


    // QWidget interface
protected:
    void keyReleaseEvent(QKeyEvent *event);
public slots:
    void closeWindow();

};
#endif // WIDGET_H
