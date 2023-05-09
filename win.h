#ifndef WIN_H
#define WIN_H

#include <QMainWindow>
#include<QPainter>

class win : public QMainWindow
{
    Q_OBJECT
    int&score;
    QString path="://source/victory.png";
public:
    explicit win(int&score,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
signals:

public slots:
};

#endif // WIN_H
