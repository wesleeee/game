#ifndef ACTOR_H
#define ACTOR_H

#include <QWidget>
#include<QLabel>
#include<iostream>
#include<QPainter>
#include<QTimer>
using namespace std;
class actor : public QLabel
{
    Q_OBJECT
    int&hero_blood;
    int x;
    int y;
    int blood;
    int&aimx;
    int&aimy;
    QString path="://source/bean.png";
    QString pathattack="://source/deadbean.png";
    bool flag=0;//判断是否要寄
    bool&ruined;
    bool died=0;
public:
    int fight=1;
    void timerEvent(QTimerEvent*);
    actor(int X,int Y,int level,int&aim1,int&aim2,int&hero_blood,bool&ruined);
    int takex(){
        return x;
    }
    int takey(){
        return y;
    }
    void paintEvent(QPaintEvent*);
    void act();
    int getx(){
        return x;
    }
    int gety(){
        return y;
    }
    void be_fucked(){
        blood-=5;
        flag=1;
        if(blood<=0&&!died){
            blood=0;
            died=1;
            this->close();
            die();
            fight=0;
        }
        update();
    }
    void be_fucked1(){
        blood-=10;
        flag=1;
        if(blood<=0&&!died){
            blood=0;
            died=1;
            this->close();
            die();
            fight=0;
        }
        update();
    }

signals:
    void die();

public slots:

};

#endif // ACTOR_H
