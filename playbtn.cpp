#include "playbtn.h"
#include<iostream>
using namespace std;

//playbtn::playbtn(QWidget *parent) : QPushButton(parent)
//{

//}
playbtn::playbtn(QString normalimg,QString pressimg){
    this->normalimgpath=normalimg;
    this->pressimgpath=pressimg;
    QPixmap pix;
    bool rat=pix.load(normalimg);
    if(!rat){
        cout<<"fail";
        return;
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0pc;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}
