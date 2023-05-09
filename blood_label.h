#ifndef BLOOD_LABEL_H
#define BLOOD_LABEL_H

#include <QWidget>
#include<QLabel>
#include<QPainter>
#include"actor.h"
class blood_label : public QLabel
{
    Q_OBJECT

    int&blood;


    QString path1="://source/blood10.png";
    QString path2="://source/blood20.png";
    QString path3="://source/blood30.png";
    QString path4="://source/blood40.png";
    QString path5="://source/blood50.png";
    QString path6="://source/blood60.png";
    QString path7="://source/blood70.png";
    QString path8="://source/blood80.png";
    QString path9="://source/blood90.png";
    QString path10="://source/blood100.png";
    QString path0="://source/blood0.png";
    QString path;
public:
    blood_label(int&blood);
    void timerEvent(QTimerEvent*);
    void paintEvent(QPaintEvent*);
signals:

public slots:
};

#endif // BLOOD_LABEL_H
