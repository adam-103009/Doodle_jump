#include "fly_monster.h"
fly_monster::fly_monster()
{
    c=1;
    n=60;
    timer=new QTimer();
    timer->start(30);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
}

void fly_monster::behavior()
{
    QPixmap G(":/image/image/fly_cat.png");
    setPixmap(QPixmap(G.scaled(50,50)));
}

int fly_monster::type()
{
    return 3;
}


void fly_monster::move()
{
    if(c==1){
        n--;
        setPos(x(),y()+3);
        if(n==0){
            c=0;
        }
    }
    else if(c==0){
        n++;
        setPos(x(),y()-3);
        if(n==60){
            c=1;
        }
    }
    if(y()>800){
        timer->stop();
    }
}

