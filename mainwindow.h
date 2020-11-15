#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QKeyEvent>
#include <QMainWindow>
#include <QGraphicsScene>
#include<QGraphicsPixmapItem>
#include"move.h"
#include<QTimer>
#include<QMouseEvent>
#include"bullet.h"
#include"props.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void rocket();


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    QGraphicsPixmapItem *Heart[3];

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    move_player *pic;
    QTimer *timer,*timer2,*t,*t_s=new QTimer;
    QFont f,f_score;
private slots:
    void jump();
    void onRepeatTimer();
    void on_pause_clicked();
    void on_continue_2_clicked();
    void do_rocket();
    void reset_time();
    void shield_time();
};

#endif // MAINWINDOW_H
