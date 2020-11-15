#include "moving_plate.h"

moving_plate::moving_plate()
{
    c=1;
    n=60;
    timer=new QTimer();
    timer->start(30);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
}

void moving_plate::move()
{
    if(c==1){
        n--;
        setPos(x()+3,y());
        if(n==0){
            c=0;
        }
    }
    else if(c==0){
        n++;
        setPos(x()-3,y());
        if(n==60){
            c=1;
        }
    }
    if(y()>800){
        timer->stop();
    }
}

void moving_plate::Picture()
{
    QPixmap G(":/image/image/box");
    setPixmap(QPixmap(G.scaled(100,20)));
}

int moving_plate::type()
{
    return 2;
}
