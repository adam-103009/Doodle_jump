#include"move.h"
#include<QKeyEvent>
#include"mainwindow.h"
#include"bullet.h"
#include<QGraphicsScene>
#include<QTimer>
#include<QVector>
#include<QDebug>
/*static QVector<Qt::Key>pressedKeys;
static QTimer *repeatTimer=new QTimer();
const int REPEAT_RATE = 20;*/

move_player::move_player()
{

    // connect(repeatTimer,SIGNAL(timeout()),this,SLOT(onRepeatTimer()));
}

void move_player::set_picture()
{

}

void move_player::condition_shield()
{
    condition=1;

}

void move_player::condition_unshield()
{
    condition=0;
}

void move_player::condition_fly()
{
    condition=2;
}

/*void move_player::keyPressEvent(QKeyEvent *e){
    pressedKeys.append(static_cast<Qt::Key>(e->key()));
       if(!repeatTimer->isActive()) {
           repeatTimer->start(REPEAT_RATE);
       }*/
    /*switch(e->key()){
    case Qt::Key_D:
        setPos(x()+10,y());
        break;

    case Qt::Key_A:
        setPos(x()-10,y());
        break;

    case Qt::Key_X:
        bullet *b=new bullet();
        QPixmap bu(":/image/image/workers");
        b->setPixmap(bu.scaled(20,50));
        b->setPos(x()+12.5,y());
        scene()->addItem(static_cast<QGraphicsPixmapItem*>(b));
        break;
    }*/

    /*if(e->key()==Qt::Key_A&&e->isAutoRepeat()==0){

            setPos(x()-10,y());

    }
    else if(e->key()==Qt::Key_D&&e->isAutoRepeat()==0){
        setPos(x()+10,y());
    }*/


/*void move_player::keyReleaseEvent(QKeyEvent *e)
{
    if(repeatTimer->isActive() && pressedKeys.isEmpty()) {
            repeatTimer->stop();
            onRepeatTimer();
        }
        pressedKeys.removeAll(static_cast<Qt::Key>(e->key()));
}*/
    /*e->isAutoRepeat();

    if(e->key()==Qt::Key_X){
        bullet *b=new bullet();
        QPixmap bu(":/image/image/workers");
        b->setPixmap(bu.scaled(20,50));
        b->setPos(x()+12.5,y());
        scene()->addItem(static_cast<QGraphicsPixmapItem*>(b));

    }*/


/*void move_player::onRepeatTimer()
{
    if(pressedKeys.contains(Qt::Key_W)) {

        }
        if(pressedKeys.contains(Qt::Key_S)) {

        }
        if(pressedKeys.contains(Qt::Key_A)) {
           setPos(x()-7,y());
        }
        if(pressedKeys.contains(Qt::Key_D)) {
            setPos(x()+7,y());
        }
        if(pressedKeys.contains(Qt::Key_H)) {
            bullet *b=new bullet();
            QPixmap bu(":/image/image/energypng");
            b->setPixmap(bu.scaled(20,50));
            b->setPos(x()+12.5,y()-30);
            scene()->addItem(static_cast<QGraphicsPixmapItem*>(b));
        }
};*/
