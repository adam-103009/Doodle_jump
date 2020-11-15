#include "prop_spring.h"

prop_spring::prop_spring()
{

}

void prop_spring::behavior()
{
    QPixmap G(":/image/image/pruz2.png");
    setPixmap(QPixmap(G.scaled(50,20)));
}

int prop_spring::type()
{
    return 1;
}
