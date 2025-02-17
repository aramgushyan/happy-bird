#include "bird.h"
#include <QGraphicsScene>
bird::bird(QPixmap pixmap)
{
    setPixmap(pixmap);
    gpos = scenePos().y()+570;

    yAnim = new QPropertyAnimation(this,"y",this);
    yAnim -> setStartValue(scenePos().y());
    yAnim->setEndValue(gpos);
    yAnim->setEasingCurve(QEasingCurve::InQuad);
    yAnim->setDuration(1000);
    yAnim->start();




}



qreal bird::y() const
{
    return m_y;
}

void bird::setY(qreal y)
{
    moveBy(0,y-m_y);
    m_y = y;
}

void bird::fall()
{
    if(y() < gpos)
    {
        yAnim -> setStartValue(y());
        yAnim->setEasingCurve(QEasingCurve::InQuad);
        yAnim->setEndValue(gpos);
        yAnim->setDuration(1200);
        yAnim->start();

    }
}

void bird::freeze()
{
    yAnim->stop();
}

void bird::flyup()
{
    yAnim->stop();

    qreal curPosY = y();

    yAnim->setStartValue(curPosY);
    yAnim->setEndValue(curPosY-scene()->sceneRect().height()/8);
    yAnim->setEasingCurve(QEasingCurve::OutQuad);
    yAnim->setDuration(285);
    connect(yAnim,&QPropertyAnimation::finished,[=](){
        fall();
    });
    yAnim->start();

}
