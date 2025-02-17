#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsPixmapItem>

#include <QKeyEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)

{
    ui->setupUi(this);
    this->setWindowTitle("Happy Bird");

    scene = new Scene(this);
    scene->setSceneRect(-150,-300,300,600);

    QGraphicsPixmapItem *pixItem = new QGraphicsPixmapItem(QPixmap(":/sky.png"));
    scene->addItem(pixItem);
    pixItem->setPos(QPointF(0,0) - QPointF(pixItem ->boundingRect().width()/2,pixItem->boundingRect().height()/2));

    connect(scene, &Scene::birdCollided, this, &Widget::closeWindow);

    m_play = new QMediaPlayer(this);
    m_list = new QMediaPlaylist(m_play);

    m_play->setPlaylist(m_list);
    m_list->addMedia(QUrl("C:/shhh/happy_bird/mya.mp3"));
    m_list -> setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    m_play->play();
    ui ->graphicsView->setScene(scene);
    scene->SceneBird();


}
void Widget::closeWindow()
{
    close();
    m_play->stop();
}

Widget::~Widget()
{

    delete ui;
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_M)
    {
        if(!flag)
        {
            m_play->setVolume(0);
            flag = true;
        }
        else
        {
            m_play->setVolume(100);
            flag = false;
        }
    }
}



