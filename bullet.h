#ifndef BULLET_H
#define BULLET_H
#include<QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
class bullet:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet();
    QTimer *timer;
public slots:
    void move_b();
};

#endif // BULLET_H
