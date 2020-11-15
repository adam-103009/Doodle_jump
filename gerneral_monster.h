#ifndef GERNERAL_MONSTER_H
#define GERNERAL_MONSTER_H
#include"monster.h"

class gerneral_monster:public monster
{
public:
    gerneral_monster();
    void behavior();
    int type();
};

#endif // GERNERAL_MONSTER_H
