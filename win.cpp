#include "win.h"
#include<QLabel>
win::win(int&score,QWidget *parent) : QMainWindow(parent),score(score)
{
    setFixedSize(1330,700);
    QLabel *Score=new QLabel(this);
    Score->setParent(this);
    Score->setText(QString::number(score));
    Score->resize(60,60);
    Score->move(635,500);
    QFont ft;
    ft.setPointSize(18);
    Score->setStyleSheet("color:red;");
    Score->setFont(ft);

}
void win::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0,0,1330,700,QPixmap(path));
}
