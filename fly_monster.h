#ifndef FLY_MONSTER_H
#define FLY_MONSTER_H
#include"monster.h"
#include<QObject>
class fly_monster:public QObject, public monster
{
    Q_OBJECT
public slots:
    void move();
public:
    fly_monster();
    void behavior();
    int type();
    int c,n;
    QTimer *timer;
};

#endif // FLY_MONSTER_H
