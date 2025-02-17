#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include "pillar.h"
#include "bird.h"
#include "changeskin.h"
class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    void SceneBird();

signals:
    void birdCollided();
public slots:
private:
    void setUpPillarTimer();
    QTimer* pillarTimer;
    bird* birdd;
    bool fla = false;
    changeskin* Change;
    bool fl = false;


    // QGraphicsScene interface
public:
    void freezeall();
    void keyPressEvent(QKeyEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
    void firstbird();
};

#endif // SCENE_H
