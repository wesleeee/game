#ifndef PLAYBTN_H
#define PLAYBTN_H

#include <QPushButton>

class playbtn : public QPushButton
{
    Q_OBJECT
public:
    //explicit playbtn(QWidget *parent = nullptr);
    playbtn(QString normalimg,QString pressimg="");
    QString normalimgpath;
    QString pressimgpath;
signals:

public slots:
};

#endif // PLAYBTN_H
