#ifndef GENPROPS_H
#define GENPROPS_H
#include"props.h"
#include"prop_spring.h"
#include"have_no_props.h"
#include"prop_rocket.h"
#include"prop_shield.h"
Props *genProps(int X,int Y){
    Props *New_props;
    int x;
    x=rand()%10;
    if(x==1){
        New_props=new prop_spring;
        New_props->setPos(X+25,Y-10);
        return New_props;
    }
    else if(x==2){
        New_props=new prop_rocket;
        New_props->setPos(X+25,Y-35);
        return New_props;
    }
    else if(x==3){
        New_props=new prop_shield;
        New_props->setPos(X+25,Y-35);
        return New_props;
    }
    else{
        New_props=new have_no_props;
        New_props->setPos(X+40,Y-50);
        return New_props;
    }
}
#endif // GENPROPS_H
