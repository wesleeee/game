#include "sweat.h"

sweat::sweat(int x1,int y1,int i,int j,actor**enemy,int&number):number(number),enemy(enemy)
{
    setFixedSize(1330,700);
    x=x1;
    y=y1;
    xi=i;
    yj=j;
    startTimer(10);
}
void sweat::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(x,y,12,12,QPixmap(path));
}
void sweat::timerEvent(QTimerEvent *event){
    x+=xi;
    y+=yj;
    update();
    if(x==0||x==1330||y==0||y==700){
        delete this;
    }
    for(int i=0;i<number;i++){
        if(x>=enemy[i]->getx()-6&&x<=enemy[i]->getx()+70&&y>=enemy[i]->gety()-6&&y<=enemy[i]->gety()+70){
            enemy[i]->be_fucked();
        }
    }
}
