#ifndef HERO_H
#define HERO_H

#include <QWidget>
#include"playwindow.h"

class hero : public QWidget
{
    Q_OBJECT
    int posx;
    int posy;
public:
    //explicit hero(QWidget *parent = nullptr);
    hero(QMainWindow*w=NULL);
signals:

public slots:
};

#endif // HERO_H
