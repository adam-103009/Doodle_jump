#ifndef GENPLATES_H
#define GENPLATES_H
#include"plates.h"
#include"general_plates.h"
#include"special_plates.h"
#include"moving_plate.h"
Plates * genPlate(int X,int Y){
    Plates * new_pla;
    int x;
    x=rand()%10;
    if(x==1){
        new_pla=new Special_Plates;
        new_pla->setPos(X,Y);
        return new_pla;
    }
    else if(x==2){
        new_pla=new moving_plate;
        new_pla->setPos(X,Y);
        return new_pla;
    }

    else{
        new_pla=new General_Plates;
        new_pla->setPos(X,Y);
        return new_pla;
    }
}

#endif // GENPLATES_H
