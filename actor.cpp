#include "actor.h"

actor::actor(int X,int Y,int level,int&aim1,int&aim2,int&hero_blood,bool&ruined):aimx(aim1),aimy(aim2),hero_blood(hero_blood),ruined(ruined)
{
    setFixedSize(1330,700);
    x=X;
    y=Y;
    blood=level;
    startTimer(20);

}
void actor::act(){

    if(x<aimx-3&&x<=1260-3&&!(ruined&&x>=1060-3&&y>430-3)){
        x+=3;
    }else if(x>aimx+3&&x>=3){
        x-=3;
    }
    if(y<aimy-3&&y<=630-3&&!(ruined&&x>1060-3&&y>=430-3)){
        y+=3;
    }else if(y>aimy+3&&y>=3){
        y-=3;
    }
    if(x>=aimx-70&&x<=aimx+70&&y>=aimy-70&&y<=aimy+100){



        if(fight>0){
            fight=0;
            if(hero_blood>0){
                hero_blood-=10;
            }


            this->close();
        }

}


    update();
}
void actor::timerEvent(QTimerEvent*){
    act();

}
void actor::paintEvent(QPaintEvent*){
    QPainter painter(this);
    if(flag){
        painter.drawPixmap(x,y,70,70,QPixmap(pathattack));
    }else{
        painter.drawPixmap(x,y,70,70,QPixmap(path));
    }

}
