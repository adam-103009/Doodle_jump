#ifndef HAVE_NO_MONSTER_H
#define HAVE_NO_MONSTER_H
#include"monster.h"

class have_no_monster:public monster
{
public:
    have_no_monster();
    void behavior();
    int type();
};

#endif // HAVE_NO_MONSTER_H
