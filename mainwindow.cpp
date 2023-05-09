#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playbtn.h"
#include<QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1330,700);
    setWindowIcon(QIcon("://source/background.png"));
    setWindowTitle("vampire survivors");
    playbtn*btn=new playbtn(":/new/prefix1/source/playbtn.png");
    btn->setParent(this);
    btn->move(this->width()*0.5-btn->width()*0.5,this->height()*0.7);

    connect(btn,&playbtn::clicked,[=](){

        QTimer::singleShot(500,this,[=](){
            this->hide();
            window=new playwindow;
            window->show();
        });
    });

}
void MainWindow::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pix;
    pix.load("://source/background.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    ui->title->setStyleSheet("color:red;");

}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionquit_triggered()
{
    this->close();
}


