#include "playwindow.h"
#include"hero.h"
#include<iostream>
#include"actor.h"
#include"sweat.h"
#include<QTimer>
#include"fire.h"
#include"posion.h"
#include"gameover.h"
#include"win.h"
using namespace std;

playwindow::playwindow(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(1330,700);
    setWindowTitle("games");
    hero_blood=100;

    obstacle=new skeleton;
    obstacle->setParent(this);
    obstacle->show();
//    enemy=new actor(x,y,10,herox,heroy);
//    enemy->setParent(this);
//    enemy->show();
//    connect(enemy,&actor::attack,this,&playwindow::be_attack);
    for(int i=number;i<number+10;i++){
        int x,y;
        int n1=rand()%4;
        int n2=rand()%1331;
        int n3=rand()%701;
        if(n1==0){
            x=0;
            y=n3;
        }else if(n1==1){
            x=n2;
            y=0;
        }else if(n1==2){
            x=1330;
            y=n3%500;
        }else{
            x=n2%1130;
            y=700;
        }
        enemy[i]=new actor(x,y,25,herox,heroy,hero_blood,ruined);
        enemy[i]->setParent(this);
        enemy[i]->show();
        connect(enemy[i],&actor::die,[=](){
            score+=5;
        });
    }
    number+=10;
    QTimer*timer=new QTimer(this) ;
    timer->start(10000);
    connect(timer,&QTimer::timeout,[=](){
        for(int i=number;i<number+10;i++){
            int x,y;
            int n1=rand()%4;
            int n2=rand()%1331;
            int n3=rand()%701;
            if(n1==0){
                x=0;
                y=n3;
            }else if(n1==1){
                x=n2;
                y=0;
            }else if(n1==2){
                x=1330;
                y=n3%500;
            }else{
                x=n2%1130;
                y=700;
            }
            enemy[i]=new actor(x,y,25,herox,heroy,hero_blood,ruined);
            enemy[i]->setParent(this);
            enemy[i]->show();
            connect(enemy[i],&actor::die,[=](){
                score+=5;
            });
        }
        number+=10;
        if(number>=120){
            timer->stop();
        }
    });
    //使用近程攻击
    fire*flame=new fire(herox,heroy,number,enemy,obstacle);
    flame->setParent(this);
    flame->show();
    bld=new blood_label(hero_blood);
    bld->setParent(this);
    bld->show();





//    blood_label=new QLabel(this);
//    blood_label->resize(300,60);
//    blood_label->setParent(this);
//    blood_label->show();
//    QTimer*time=new QTimer(this);
//    time->start(10);
//    connect(time,&QTimer::timeout,[=](){
//        blood_label->setText(QString::number(hero_blood));

//    });

    connect(flame,&fire::obstacle_killed,[=](){
        obstacle->close();
        ruined=1;
        drug=new posion(herox,heroy);
        drug->setParent(this);
        drug->show();
        showed=1;
        connect(drug,&posion::betouched,[=](){
            drug->close();
            startTimer(1500);
        });
    });//破坏障碍物


    QTimer*ttime=new QTimer(this);
    ttime->start(10);
    connect(ttime,&QTimer::timeout,[=](){
        if(hero_blood==0&&closed==0){
            gameover*over=new gameover(score);
            closed=1;
            this->close();
            over->show();
            ttime->stop();
        }
    });//失败


    QTimer*tttime=new QTimer(this);
    tttime->start(120000);

    connect(tttime,&QTimer::timeout,[=](){
        if(hero_blood!=0&&closed==0){
            win*won=new win(score);
            closed=1;
            this->close();
            won->show();
            tttime->stop();
        }

    });//胜利


}
void playwindow::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_W){
        showhero=!showhero;
        heroy<=0? heroy=heroy:heroy-=7;
        update();
    }else if(event->key()==Qt::Key_S){
        showhero=!showhero;
       // heroy>=600? heroy=heroy:heroy+=7;
        if(heroy>=600||!ruined&&(heroy>=400&&herox>1060)){
            heroy=heroy;
        }else{
            heroy+=7;
        }
        update();
    }else if(event->key()==Qt::Key_A){
        showhero=!showhero;
        herox<=0? herox=herox:herox-=7;

        update();
    }else if(event->key()==Qt::Key_D){
        showhero=!showhero;
        //herox>=1260? herox=herox:herox+=7;
        if(herox>=1260||!ruined&&(herox>=1060&&heroy>406)){
            herox=herox;
        }else{
            herox+=7;
        }
        update();
    }

}
void playwindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    pix.load("://source/ground");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    if(showhero){
      pix.load("://source/hero1.png");
      painter.drawPixmap(herox,heroy,70,100,pix);
    }else{
        pix.load("://source/hero2.png");
        painter.drawPixmap(herox,heroy,70,100,pix);
    }

}




void playwindow::make_weapon(int i, int j){
    sweat*water=new sweat(herox,heroy,i,j,enemy,number);
    water->setParent(this);
    water->show();
}
void playwindow::timerEvent(QTimerEvent *){
    make_weapon(3,3);
    make_weapon(-3,3);
    make_weapon(3,-3);
    make_weapon(-3,-3);
    make_weapon(0,3);
    make_weapon(0,-3);
    make_weapon(3,0);
    make_weapon(-3,0);
}

