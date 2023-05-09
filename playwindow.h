#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include<QKeyEvent>
#include"actor.h"
#include"blood_label.h"
#include"skeleton.h"
#include"posion.h"
class playwindow : public QMainWindow
{
    Q_OBJECT
    int herox=500;
    int heroy=300;
    int showhero=0;
    int hero_blood=100;

    actor*enemy[120];
    int number=0;//已经出现的敌人的个数
   // QLabel*blood_label;
    blood_label*bld;
   int score=0;
   skeleton*obstacle;
   bool ruined=0;//判断障碍物毁坏
   posion*drug;
   bool showed=0;
   bool closed=0;
public:
    explicit playwindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent*);
   // void make_enemy(int number);
    void make_weapon(int i,int j);
    void timerEvent(QTimerEvent*);
signals:

public slots:

};

#endif // PLAYWINDOW_H
