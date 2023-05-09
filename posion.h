#ifndef POSION_H
#define POSION_H

#include <QWidget>
#include<QLabel>
#include<QPainter>
#include<QTimer>
class posion : public QLabel
{
    Q_OBJECT
    QString path="://source/posion.png";
    bool touched=0;
    int&x;
    int&y;
public:
    posion(int&x,int&y);
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent*);
signals:
    void betouched();

public slots:
};

#endif // POSION_H
