#include "prop_rocket.h"

prop_rocket::prop_rocket()
{

}

void prop_rocket::behavior()
{
    QPixmap p(":/image/image/doodle-sprites-2.png");
    setPixmap(QPixmap(p.scaled(50,50)));

}

int prop_rocket::type()
{
    return 2;
}
