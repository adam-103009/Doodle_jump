#ifndef GENMONSTER_H
#define GENMONSTER_H
#include"monster.h"
#include"gerneral_monster.h"
#include<ctime>
#include"have_no_monster.h"
#include"fly_monster.h"
monster *genmonster(int X,int Y){
    monster *New_monster;
    int x;

    x=rand()%20;

    if((x==1)&&X<=500){
    New_monster=new gerneral_monster;
    New_monster->setPos(X+30,Y-50);
    return New_monster;
    }
    else if((x==3)&&X<=450){
        New_monster=new fly_monster;
        New_monster->setPos(X+150,Y);
        return New_monster;
    }
    else {
        New_monster= new have_no_monster;
        return New_monster;
    }


}
#endif // GENMONSTER_H
