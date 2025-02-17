#ifndef BIRD_H
#define BIRD_H

#include <QTimer>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class bird : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal y READ y WRITE setY )
public:
    bird(QPixmap pixmap );

    qreal y() const;

    void flyup();

signals:
public slots:
    void setY(qreal newY);
    void fall();
    void freeze();
private:
    qreal m_y;
    QPropertyAnimation * yAnim;
    qreal gpos;
};

#endif // BIRD_H
