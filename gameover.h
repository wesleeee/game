#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QMainWindow>
#include<QPainter>

class gameover : public QMainWindow
{
    Q_OBJECT
    QString path="://source/gameover.png";
    int&score;
public:
    gameover(int&score,QWidget*parent=nullptr);
    void paintEvent(QPaintEvent*);
signals:

public slots:
};

#endif // GAMEOVER_H
