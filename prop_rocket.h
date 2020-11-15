#ifndef PROP_ROCKET_H
#define PROP_ROCKET_H
#include"props.h"

class prop_rocket:public Props
{
public:
    prop_rocket();
    void behavior();
    int type();
};

#endif // PROP_ROCKET_H
