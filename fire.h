#ifndef FIRE_H
#define FIRE_H

#include <QWidget>
#include<QLabel>
#include"actor.h"
#include"skeleton.h"
class fire : public QLabel
{
    Q_OBJECT
    int&x;
    int&y;
    int&number;
    actor**enemy;
    QString path="://source/fire.png";
    int t=0;
    int xi;
    int yi;
    skeleton*skull;

public:
    fire(int&x1,int&y1,int&number,actor**enemy,skeleton*skull);
    void paintEvent(QPaintEvent*);
    void timerEvent(QTimerEvent*);

signals:
    void obstacle_killed();

public slots:
};

#endif // FIRE_H
