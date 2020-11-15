#ifndef MONSTER_H
#define MONSTER_H
#include<QGraphicsPixmapItem>
#include<QTimer>
#include<QGraphicsScene>
class monster:public QGraphicsPixmapItem
{
public:
    monster();
    virtual void behavior();
    virtual int type();
};

#endif // MONSTER_H
