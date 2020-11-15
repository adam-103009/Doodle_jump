#include "special_plates.h"

Special_Plates::Special_Plates()
{


}

void Special_Plates::Picture()
{
    QPixmap S(":/image/image/wall.png");
    setPixmap(QPixmap(S.scaled(100,20)));

}

int Special_Plates::type()
{
    return 0;
}
