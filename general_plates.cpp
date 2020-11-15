#include "general_plates.h"

General_Plates::General_Plates()
{

}

void General_Plates::Picture()
{

 QPixmap G(":/image/image/box");
 setPixmap(QPixmap(G.scaled(100,20)));
}

int General_Plates::type()
{
    return 1;
}
