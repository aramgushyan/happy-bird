#ifndef PILLAR_H
#define PILLAR_H


#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
class pillar :public QObject ,public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)
public:
    explicit pillar();
    ~pillar();
    qreal x() const;
signals:
    void fail();
public slots:
    void setX(qreal x);
    void freeez();
private:
    bool Crush();
    QGraphicsPixmapItem * topPillar;
    QGraphicsPixmapItem * bottomPillar;
    QPropertyAnimation * xAnimation;
    int yPos;

    qreal m_x;



};

#endif // PILLAR_H
