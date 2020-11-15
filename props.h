#ifndef PROPS_H
#define PROPS_H
#include<QGraphicsPixmapItem>

class Props:public QGraphicsPixmapItem
{
public:
    Props();
    virtual void behavior();
    virtual int type();
};

#endif // PROPS_H
