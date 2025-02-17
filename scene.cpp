#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <restart.h>
#include <QString>
Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    setUpPillarTimer();

}

void Scene::setUpPillarTimer()
{

    pillarTimer = new QTimer (this);
    connect(Change,&changeskin::change,this,&Scene::firstbird);
    connect(pillarTimer,&QTimer::timeout,[=](){
       pillar* pillarr = new pillar();

       connect(pillarr,&pillar::fail,[=](){
           pillarTimer->stop();
           freezeall();
           fla = true;
           restart* fwind = new restart;
           fwind->showNormal();
           emit birdCollided();


       });
       addItem(pillarr);
    });
    pillarTimer->start(1500);

}

void Scene::freezeall()
{
    birdd->freeze();
    QList<QGraphicsItem*> sceneItems = items();
    foreach (QGraphicsItem * item,sceneItems)
    {
        pillar * pillarr = dynamic_cast<pillar*>(item);
        if (pillarr)
        {
            pillarr->freeez();
        }
    }
}
void Scene::firstbird()
{
    birdd = new bird(QPixmap("C:/shhh/happy_bird/bird.png"));
    fl = true;
}
void Scene::SceneBird()
{

    addItem(birdd);
    birdd->setPos(QPointF(-900,-300));
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if((event->key()==Qt::Key_Space) and ( !fla))
    {
        birdd->flyup();
    }
    QGraphicsScene::keyPressEvent(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton and ( !fla)){
        birdd->flyup();
    }
    QGraphicsScene::mousePressEvent(event);

}






