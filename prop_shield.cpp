#include "prop_shield.h"

prop_shield::prop_shield()
{

}

void prop_shield::behavior()
{
    QPixmap p(":/image/image/shield.png");
    setPixmap(QPixmap(p.scaled(30,30)));
}

int prop_shield::type()
{
    return 3;

}
