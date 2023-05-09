#ifndef SKELETON_H
#define SKELETON_H

#include <QWidget>
#include<QLabel>
#include<QPainter>

class skeleton : public QLabel
{
    Q_OBJECT
    int blood=10;
    QString path="://source/skeleton.png";
public:
    skeleton();
    void paintEvent(QPaintEvent*);
    void fucked(){
        blood--;
    }
    bool dead(){
        return blood==0?true:false;
    }
signals:
    void prize();
public slots:
};

#endif // SKELETON_H
