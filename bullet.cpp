#include "bullet.h"
#include<QTimer>
#include"gerneral_monster.h"
#include"have_no_monster.h"
#include"fly_monster.h"
#include<QDebug>
bullet::bullet()
{
    timer=new QTimer();
    timer->start(10);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_b()));
}

void bullet::move_b()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
       for (int i = 0,n = colliding_items.size(); i < n; i++){
           if (typeid(*(colliding_items[i])) == typeid(gerneral_monster)|| typeid(*(colliding_items[i])) == typeid(fly_monster)){
               colliding_items[i]->setPos(0,1000);
              // qDebug()<<n;
               scene()->removeItem(this);
               delete this;
               return;
           }
       }

    setPos(x(),y()-3);
    if(y()<0){
        this->scene()->removeItem(this);
        timer->stop();
    }
}











