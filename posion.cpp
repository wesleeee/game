#include "posion.h"
#include<QTimer>
posion::posion(int&x,int&y):x(x),y(y)
{
    setFixedSize(1330,700);
    startTimer(1);
}
void posion::paintEvent(QPaintEvent *){

        QPainter painter(this);
        painter.drawPixmap(1160,520,50,50,path);


}
void posion::timerEvent(QTimerEvent *event){
    if(x>=1160-70&&x<1160+50&&y>=520-100&&y<520+50&&!touched){
        betouched();
        touched=1;
    }
}
