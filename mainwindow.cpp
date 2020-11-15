#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QDebug>
#include"move.h"
#include<cstdlib>
#include"bullet.h"
#include"plates.h"
#include"general_plates.h"
#include"special_plates.h"
#include"monster.h"
#include"gerneral_monster.h"
#include"genmonster.h"
#include"genplates.h"
#include"genprops.h"
#define N 10
static Props *pro[N];
static double du=0.2;
static int T=10;
static bullet *b;
static QVector<Qt::Key>pressedKeys;
static QTimer *repeatTimer=new QTimer();
const int REPEAT_RATE = 20;
static monster *monster[N],*cal_heart;
static int c=200,C=20;
static int X=100,Y=300,h=400,PY,n=0,monster_position[N],pla_position[N],props_position[N],heart=3;
static float dy=0;
static Plates *pla[N],*cal_points;
struct position{
    int x,y;
};
static position P[N];
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    for(int i=1;i<N;i++){
        P[i].x=45*i;
        P[i].y=70*i;
    }
    f.setPointSize(50);
    f_score.setPointSize(20);
    ui->gameover->setFont(f);
    ui->gameover->setVisible(false);
    ui->SCORE->setVisible(false);
    t=new QTimer;
    QPixmap PLA(":/image/image/box");
    QPixmap player(":/image/image/doodle_right.png");
    P[0].x=200;
    P[0].y=780;
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,500,800);
    ui->graphicsView->setScene(scene);
    pla[0]=new General_Plates;
    pla[0]->setPos(P[0].x,P[0].y);
    pla[0]->Picture();
    scene->addItem(pla[0]);
    monster[0]=new have_no_monster;
    monster[0]->setPos(P[0].x,P[0].y);
    monster[0]->behavior();
    scene->addItem(monster[0]);
    pro[0]=new have_no_props;
    pro[0]->setPos(P[0].x,P[0].y);
    pro[0]->behavior();
    scene->addItem(pro[0]);
    for(int i=1;i<N;i++){
        pla[i]=genPlate(P[i].x,P[i].y);
        pla[i]->Picture();
        scene->addItem(pla[i]);
        if(pla[i]->type()==2){
            pro[i]=new have_no_props;
            pro[i]->setPos(P[i].x,P[i].y);
            pro[i]->behavior();
            scene->addItem(pro[i]);
            monster[i]=new have_no_monster;
            monster[i]->setPos(P[i].x,P[i].y);
            monster[i]->behavior();
            scene->addItem(monster[i]);
        }
        else{
        pro[i]=genProps(P[i].x,P[i].y);
        pro[i]->behavior();
        scene->addItem(pro[i]);
        monster[i]=genmonster(P[i].x,P[i].y);
        monster[i]->behavior();
        scene->addItem(monster[i]);
        }
    }
    pic=new move_player();

    /*QPixmap plates(":/image/image/box");
    for(int i=0;i<10;i++){
        QGraphicsPixmapItem *plat=new QGraphicsPixmapItem();
        plat->setPixmap(QPixmap(plates.scaled(50,10)));
        scene->addItem(plat);
        plat->setPos(P[i].x,P[i].y);
    }*/
    pic->setPixmap(QPixmap(player.scaled(75,70)));
    pic->setPos(200,100);
    scene->addItem(pic);
    pic->setFlag(QGraphicsItem::ItemIsFocusable);
    pic->setFocus();
    timer=new QTimer();
    timer->start(T);
    connect(timer,SIGNAL(timeout()),this,SLOT(jump()));
    connect(repeatTimer,SIGNAL(timeout()),this,SLOT(onRepeatTimer()));
    connect(t,SIGNAL(timeout()),this,SLOT(reset_time()));
    connect(this,SIGNAL(rocket()),this,SLOT(do_rocket()));
    connect(t_s,SIGNAL(timeout()),this,SLOT(shield_time()));
    ui->continue_2->setVisible(false);
    pic->condition_unshield();
    QPixmap H(":/image/image/heart.png");
    for(int i=0;i<3;i++){
        Heart[i]=new QGraphicsPixmapItem();
        Heart[i]->setPixmap(H.scaled(40,40));
        Heart[i]->setPos(0,i*50);
        scene->addItem(Heart[i]);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_A){
        QPixmap Left_S(":/image/image/Shield_left .png");
        QPixmap Left(":/image/image/doodle_left.png");
        QPixmap Left_fly(":/image/image/doodle_left_rocket.png");
        if(pic->condition==0){
            pic->setPixmap(QPixmap(Left.scaled(75,70)));
        }
        else if(pic->condition==1){
            pic->setPixmap(QPixmap(Left_S.scaled(70,70)));
        }
        else  if(pic->condition==2){
            pic->setPixmap(QPixmap(Left_fly.scaled(70,70)));
        }
    }
    else if(e->key()==Qt::Key_D){
        QPixmap Right_S(":/image/image/shield (1).png");
        QPixmap Right(":/image/image/doodle_right.png");
        QPixmap Right_fly(":/image/image/doodle_right_rocket 拷貝.png");
        if(pic->condition==0){
            pic->setPixmap(QPixmap(Right.scaled(75,70)));
        }
        else if(pic->condition==1){
            pic->setPixmap(QPixmap(Right_S.scaled(70,70)));
        }
        else if(pic->condition==2){
            pic->setPixmap(QPixmap(Right_fly.scaled(70,70)));
        }
    }
    else if(e->key()==Qt::Key_H){
        QPixmap shoot_shield(":/image/image/Shield_shot.png");
        QPixmap shoot(":/image/image/doodle-shoot.png");
        if(pic->condition==0){
        pic->setPixmap(QPixmap(shoot.scaled(50,50)));
        }
        else if(pic->condition==1){
            pic->setPixmap(QPixmap(shoot_shield.scaled(70,70)));
        }
    }

    pressedKeys.append(static_cast<Qt::Key>(e->key()));
       if(!repeatTimer->isActive()) {
           repeatTimer->start(REPEAT_RATE);
       }
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    if((e->key()==Qt::Key_H)){
        QPixmap Left(":/image/image/doodle_left.png");
        pic->setPixmap(QPixmap(Left.scaled(75,70)));
    }

    if(repeatTimer->isActive() && pressedKeys.isEmpty()) {
            repeatTimer->stop();
            onRepeatTimer();
        }
        pressedKeys.removeAll(static_cast<Qt::Key>(e->key()));
}


void MainWindow::jump()
{
    dy +=du;
    Y+=dy;
    ui->score->setNum(n);
    //qDebug()<<Y<<"\n";
    if(Y>800){
        timer->stop();
        ui->gameover->setVisible(true);
        ui->score->setGeometry(200,300,300,100);
        ui->score->setFont(f_score);
        ui->SCORE->setVisible(true);
        ui->SCORE->setGeometry(100,300,350,100);
        ui->SCORE->setFont(f_score);
    }
    if(Y<h){
            Y=h;
            for(int I=0;I<N;I++){
            P[I].y=P[I].y-dy;
            monster_position[I]=monster[I]->y()-dy;
            props_position[I]=pro[I]->y()-dy;
            pla_position[I]=pla[I]->y()-dy;
            if(P[I].y>=800){
                monster_position[I]=-25;
                props_position[I]=0;
                pla_position[I]=25;
                P[I].y=25;
                P[I].x=45*(rand()%9);

                scene->removeItem(pla[I]);
                pla[I]=genPlate(P[I].x,pla_position[I]);
                pla[I]->Picture();
                scene->addItem(pla[I]);
                scene->removeItem(monster[I]);
                scene->removeItem(pro[I]);
                if(pla[I]->type()==2){
                    pro[I]=new have_no_props;
                    pro[I]->setPos(P[I].x,props_position[I]);
                    pro[I]->behavior();
                    scene->addItem(pro[I]);
                    monster[I]=new have_no_monster;
                    monster[I]->setPos(P[I].x,monster_position[I]);
                    monster[I]->behavior();
                    scene->addItem(monster[I]);
                }
                else {
                pro[I]=genProps(P[I].x,props_position[I]);
                pro[I]->behavior();
                scene->addItem(pro[I]);
                monster[I]=genmonster(P[I].x,monster_position[I]);
                monster[I]->behavior();
                scene->addItem(monster[I]);
                }

            }
            }
            for(int i=0;i<N;i++){
            monster[i]->setPos(monster[i]->x(),monster_position[i]);
            pla[i]->setPos(pla[i]->x(),pla_position[i]);
            pro[i]->setPos(pro[i]->x(),props_position[i]);
            }
    }
    for(int I=0;I<N;I++){
        if((pic->collidesWithItem(pla[I])&&(pic->y()<=pla[I]->y())&&dy>0&&pla[I]->type()==1)){
             dy=-10;
             if(cal_points!=pla[I]){
                 n+=100;
                 cal_points=pla[I];
             }
        }
        else if(pic->collidesWithItem(pla[I])&&(pic->y()+50<=pla[I]->y())&&pla[I]->type()==2&&dy>0){
            dy=-10;
            if(cal_points!=pla[I]){
                n+=100;
                cal_points=pla[I];
            }
        }
        else if(pic->collidesWithItem(pla[I])&&(pic->y()+50<=pla[I]->y())&&dy>0&&pla[I]->type()==0){
            dy=-10;
            if(cal_points!=pla[I]){
                n+=100;
                cal_points=pla[I];
            }
            pla[I]->setPos(pla[I]->x(),1000);
        }
        else if(pic->collidesWithItem(pro[I])&&(pic->y()+50<=pro[I]->y())&&dy>0&&pro[I]->type()==1){
            dy=-15;
            n+=500;
        }
        else if(pic->collidesWithItem(pro[I])&&pro[I]->type()==2){
            n+=1000;
            timer->start(20);
            du=0.1;
            dy=-40;
            pic->condition_fly();
            QPixmap F(":/image/image/doodle_right_rocket 拷貝.png");
            pic->setPixmap(F.scaled(70,70));
            emit rocket();
        }
        else if(pic->collidesWithItem(pro[I])&&(pro[I]->type()==3)&&pic->condition!=2){
            pic->condition_shield();
            pro[I]->setPos(900,100);
            QPixmap S(":/image/image/shield (1).png");
            pic->setPixmap(QPixmap(S.scaled(70,70)));
            t_s->start(2000);
        }
    }
    pic->setPos(pic->x(),Y);
    if(pic->x()>500){
        pic->setPos(0,pic->y());
    }
    else if(pic->x()<0){
        pic->setPos(500,pic->y());
    }
    for(int i=0;i<N;i++){
     if((pic->condition==0)&&(pic->collidesWithItem(monster[i]))&&(monster[i]->type()==1||monster[i]->type()==3)){
         if(cal_heart!=monster[i]){
       scene->removeItem(Heart[heart-1]);
       heart--;
       cal_heart=monster[i];
         }
       if(heart==0){
       timer->stop();
       ui->gameover->setVisible(true);
       ui->score->setGeometry(200,300,300,100);
       ui->score->setFont(f_score);
       ui->SCORE->setVisible(true);
       ui->SCORE->setGeometry(100,300,350,100);
       ui->SCORE->setFont(f_score);
       }
    }
    }


}

void MainWindow::onRepeatTimer()
{
    if(pressedKeys.contains(Qt::Key_W)) {

        }
        if(pressedKeys.contains(Qt::Key_S)) {

        }
        if(pressedKeys.contains(Qt::Key_A)) {
           pic->setPos(pic->x()-7,pic->y());
        }
        if(pressedKeys.contains(Qt::Key_D)) {
            pic->setPos(pic->x()+7,pic->y());
        }
        if(pressedKeys.contains(Qt::Key_H)) {
            b=new bullet();
            QPixmap bu(":/image/image/energypng");
            b->setPixmap(bu.scaled(20,50));
            b->setPos(pic->x()+12.5,pic->y()-30);
            scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
        }
}
void MainWindow::on_pause_clicked()
{
    timer->stop();
    ui->continue_2->setVisible(true);
}

void MainWindow::on_continue_2_clicked()
{
    timer->start(10);
    ui->continue_2->setVisible(false);
}

void MainWindow::do_rocket()
{

       t->start(1000);
}

void MainWindow::reset_time()
{
    t->stop();
    dy=0;
    timer->start(10);
    du=0.2;
    pic->condition_unshield();
}

void MainWindow::shield_time()
{
    t_s->stop();
    pic->condition_unshield();
    QPixmap S(":/image/image/doodle_right.png");
    pic->setPixmap(QPixmap(S.scaled(75,70)));
}
