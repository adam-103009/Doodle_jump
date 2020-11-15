#include"gerneral_monster.h"

gerneral_monster::gerneral_monster()
{

}

void gerneral_monster::behavior()
{
    QPixmap G(":/image/image/monster_LuLu.png");
    setPixmap(QPixmap(G.scaled(50,50)));
}

int gerneral_monster::type()
{
    return 1;
}


