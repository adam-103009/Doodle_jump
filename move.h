#ifndef MOVE_H
#define MOVE_H
#include<QGraphicsPathItem>
#include<QKeyEvent>
class move_player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    move_player();
public:
    void set_picture();
    void condition_shield();
    void condition_unshield();
    void condition_fly();
    int condition;
    /*void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);*/
private slots:
   // void onRepeatTimer();

};
#endif // MOVE_H
