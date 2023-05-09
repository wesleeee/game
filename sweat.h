#ifndef SWEAT_H
#define SWEAT_H

#include <QWidget>
#include<QLabel>
#include<QPainter>
#include"actor.h"
class sweat : public QLabel
{
    Q_OBJECT
    int x;
    int y;
    int xi;
    int yj;
    int&number;
    actor**enemy;
    QString path="://source/sweat.png";

    friend class playwindow;
public:
    sweat(int x1,int y1,int i,int j,actor**enemy,int&number);
    void paintEvent(QPaintEvent*);
    void timerEvent(QTimerEvent*);
signals:
public slots:
};

#endif // SWEAT_H
