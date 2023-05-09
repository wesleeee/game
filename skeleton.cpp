#include "skeleton.h"

skeleton::skeleton(){
    setFixedSize(1330,700);
}
void skeleton::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(1130,500,200,200,path);
}
