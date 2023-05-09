#include "hero.h"
#include<iostream>
using namespace std;

hero::hero(QMainWindow*w){
    QPainter painter(w);
    painter.drawPixmap(20,0,70,100,QPixmap(":://source/hero3"));
}
