#ifndef MOVING_PLATE_H
#define MOVING_PLATE_H
#include"plates.h"
#include<QTimer>
#include<QObject>
class moving_plate:public QObject ,public Plates
{
    Q_OBJECT
public:
    moving_plate();
    void Picture();
    int type();
    int c,n;
    QTimer *timer;
public slots:
    void move();
};

#endif // MOVING_PLATE_H
