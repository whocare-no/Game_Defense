#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QDebug>
#include<QMouseEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),c(386,281)
{
    ui->setupUi(this);
    srand(unsigned (time(nullptr)));

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap map;
    map.load("../Defense_Game/Resource/map.png");
    painter.drawPixmap(0,0,map);
    if(_c.existed()==true)
        _c.drawPoet(&painter);
    for (int i=0;i<16;i++) {
        if(pos[i].poetexitd()==true)
        poet[i].drawPoet(&painter);
    }
    for(int i=0;i<16;i++)
    {
        if(poet[i].existed()==true&&poet[i].poetdrawed==false)
        poet[i].drawPoet(&painter);
        else if(poet[i].existed()==true&&poet[i].poetdrawed==true)
            poet[i].drawRange(&painter);
    }

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    if(abs(pressPos.x()-c.x())<5&&abs(pressPos.y()-c.y())<5)
    {

       t=rand()%5;
       _c.getType(t);
       _c.getFigure();
       _c.build();
       flag=true;
        update();
     }
    for (int i=0;i<16;i++) {
        if(pos[i].Pointcontained(pressPos)==true&&pos[i].poetexitd()==false&&flag==true)
        {
            poet[i].getType(t);
            poet[i].getFigure();
            j++;
            poet[i].build();
            pos[i].getExistence(true);
            _c.unbuild();
            flag=false;
            update();
        }
        else if(pos[i].Pointcontained(pressPos)==true&&pos[i].poetexitd()==true&&poet[i].poetdrawed==false)
        {
            poet[i].poetdrawed=true;
            update();
        }
        else if(pos[i].Pointcontained(pressPos)==true&&pos[i].poetexitd()==true&&poet[i].poetdrawed==true)
        {
            poet[i].poetdrawed=false;
            update();
        }
    }
}
