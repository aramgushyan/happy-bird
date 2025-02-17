#include "pillar.h"
#include <QRandomGenerator>
#include <QGraphicsScene>
#include <QDebug>
#include <bird.h>
pillar::pillar() :
 topPillar(new QGraphicsPixmapItem(QPixmap(":/pillar.png"))),
 bottomPillar(new QGraphicsPixmapItem(QPixmap(":/pillar.png")))
{
    topPillar->setPos(QPointF(0,0)-QPointF(topPillar->boundingRect().width()/2,topPillar->boundingRect().height() +95));
    bottomPillar ->setPos(QPointF(0,0)-QPointF(bottomPillar->boundingRect().width()/2,60));

    addToGroup(topPillar);
    addToGroup(bottomPillar);

    yPos = QRandomGenerator:: global()->bounded(250);
    int xRandom = QRandomGenerator::global()->bounded(300);

    setPos(QPoint(0,0)+QPoint(950+xRandom,yPos));

    xAnimation = new QPropertyAnimation(this,"x",this);
    xAnimation -> setStartValue(1050+xRandom);
    xAnimation ->setEndValue(-1000);
    xAnimation -> setEasingCurve(QEasingCurve::Linear);
    xAnimation -> setDuration(3000);
    connect(xAnimation,&QPropertyAnimation::finished,[=](){
        scene()->removeItem(this);
        delete this;
    });

    xAnimation ->start();


}

pillar::~pillar()
{

}

qreal pillar::x() const
{
    return m_x;
}

void pillar::setX(qreal x)
{
//    qDebug() << x;
    m_x = x;
    if (Crush())
    {
        emit fail();
    }
    setPos(QPointF(0,0)+QPointF(x,yPos));
}

void pillar::freeez()
{
    xAnimation->stop();
}

bool pillar::Crush()
{
    QList<QGraphicsItem*>collidingItems = topPillar->collidingItems();
    collidingItems.append(bottomPillar->collidingItems());

    foreach(QGraphicsItem *item,collidingItems)
    {
        bird * bir = dynamic_cast<bird*>(item);
        if (bir)
        {
            return true;
        }
    }
    return false;
}
