#ifndef PLATES_H
#define PLATES_H
#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
class Plates:public QGraphicsPixmapItem
{
public:
    Plates();
    virtual void Picture();
    virtual int type();
};
#endif // PLATES_H
