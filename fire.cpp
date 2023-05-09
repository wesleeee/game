#include "fire.h"

fire::fire(int&x1,int&y1,int&number,actor**enemy,skeleton*skull):x(x1),y(y1),number(number),enemy(enemy),skull(skull){
    setFixedSize(1330,700);
    startTimer(20);
}
void fire::paintEvent(QPaintEvent *){
    QPainter painter(this);
    switch(t){
    case 0:
        xi=x-60;
        yi=y-60;
        painter.drawPixmap(x-60,y-60,30,30,QPixmap(path));
        break;
    case 1:
        xi=x-30;
        yi=y-70;
        painter.drawPixmap(x-30,y-70,30,30,QPixmap(path));
        break;
    case 2:
        xi=x+35;
        yi=y-80;
        painter.drawPixmap(x+35,y-80,30,30,QPixmap(path));
        break;
    case 3:
        xi=x+70+30;
        yi=y-80;
        painter.drawPixmap(x+70+30,y-70,30,30,QPixmap(path));
        break;
    case 4:
        xi=x+70+60;
        yi=y-60;
        painter.drawPixmap(x+70+60,y-60,30,30,QPixmap(path));
        break;
    case 5:
        xi=x+70+70;
        yi=y-30;
        painter.drawPixmap(x+70+70,y-30,30,30,QPixmap(path));
        break;
    case 6:
        xi=x+70+80;
        yi=y+50;
        painter.drawPixmap(x+70+80,y+50,30,30,QPixmap(path));
        break;
    case 7:
        xi=x+70+70;
        yi=y+100+30;
        painter.drawPixmap(x+70+70,y+100+30,30,30,QPixmap(path));
        break;
    case 8:
        xi=x+70+60;
        yi=y+100+60;
        painter.drawPixmap(x+70+60,y+100+60,30,30,QPixmap(path));
        break;
    case 9:
        xi=x+70+30;
        yi=y+100+70;
        painter.drawPixmap(x+70+30,y+100+70,30,30,QPixmap(path));
        break;
    case 10:
        xi=x+35;
        yi=y+100+80;
        painter.drawPixmap(x+35,y+100+80,30,30,QPixmap(path));
        break;
    case 11:
        xi=x-30;
        yi=y+100+70;
        painter.drawPixmap(x-30,y+100+70,30,30,QPixmap(path));
        break;
    case 12:
        xi=x-60;
        yi=y+100+60;
        painter.drawPixmap(x-60,y+100+60,30,30,QPixmap(path));
        break;
    case 13:
        xi=x-70;
        yi=y+100+30;
        painter.drawPixmap(x-70,y+100+30,30,30,QPixmap(path));
        break;
    case 14:
        xi=x-80;
        yi=y+50;
        painter.drawPixmap(x-80,y+50,30,30,QPixmap(path));
        break;
    default:
        xi=x-70;
        yi=y-30;
        painter.drawPixmap(x-70,y-30,30,30,QPixmap(path));
    }










}
void fire::timerEvent(QTimerEvent *event){
    if(t==0){
        t=1;
    }else if(t==1){
        t=2;
    }else if(t==2){
        t=3;
    }else if(t==3){
        t=4;
    }else if(t==4){
        t=5;
    }else if(t==5){
        t=6;
    }else if(t==6){
        t=7;
    }else if(t==7){
        t=8;
    }else if(t==8){
        t=9;
    }else if(t==9){
        t=10;
    }else if(t==10){
        t=11;
    }else if(t==11){
        t=12;
    }else if(t==12){
        t=13;
    }else if(t==13){
        t=14;
    }else if(t==14){
        t=15;
    }else if(t==15){
        t=0;
    }




    update();
    for(int i=0;i<number;i++){
        if(xi>=enemy[i]->getx()-24&&xi<=enemy[i]->getx()+70&&yi>=enemy[i]->gety()-24&&yi<=enemy[i]->gety()+70){
            enemy[i]->be_fucked1();
        }
    }
    if(xi>=1130-30&&yi>=500-30){
        skull->fucked();
        if(skull->dead()){
            obstacle_killed();
        }
    }
}
