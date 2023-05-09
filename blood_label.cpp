#include "blood_label.h"

blood_label::blood_label(int&blood):blood(blood){
    startTimer(1);
}
void blood_label::paintEvent(QPaintEvent *){
    switch(blood){
    case 10:
        path=path1;
        break;
    case 20:
        path=path2;
        break;
    case 30:
        path=path3;
        break;
    case 40:
        path=path4;
        break;
    case 50:
        path=path5;
        break;
    case 60:
        path=path6;
        break;
    case 70:
        path=path7;
        break;
    case 80:
        path=path8;
        break;
    case 90:
        path=path9;
        break;
    case 100:
        path=path10;
        break;
    default:
        path=path0;

    }
    QPainter painter(this);
    painter.drawPixmap(0,0,300,30,path);
}

void blood_label::timerEvent(QTimerEvent*){
    update();
//    for(int i=0;i<number;i++){
//        if(x+10>=enemy[i]->getx()&&y+60>=enemy[i]->gety()&&x<=enemy[i]->getx()&&y<=enemy[i]->gety()){
//            if(enemy[i]->fight==1){
//                blood-=10;
//                enemy[i]->fight=0;
//            }
//            update();
//        }
//    }
    //        if(fight>0){
    //            fight--;
    //            hero_blood-=10;
    //            this->close();
    //        }//    if(x>=aimx&&x<=aimx+1&&y>=aimy&&y<=aimy+60)
}
