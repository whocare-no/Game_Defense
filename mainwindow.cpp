#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QDebug>
#include<QMouseEvent>

#define WAVE 20
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),c(386,281)
{
    ui->setupUi(this);
    poetgetPos();
    srand(unsigned (time(nullptr)));    
    id1=startTimer(100);
    id2=startTimer(2000);
    id3=startTimer(30000);
    id4=startTimer(50);

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::poetgetPos()
{
    _c.setPos(QPoint(100,318));
    for(int i=0;i<16;i++)
        poet[i].setPos(pos[i].getPos());
}
void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPixmap map;
    map.load("../Defense_Game/Resource/map.png");
    painter.drawPixmap(0,0,map);
    drawMoney(&painter);
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
    for(int i=0;i<16;i++)
    {
        poet[i].chooseEnemy(enemy);
        if(poet[i].hastarget==true&&poet[i].existed()==true)
        {
            poet[i].drawBullet(&painter);
        }

    }
    for(int i=0;i<2*WAVE;i++)
    {
        if(enemy[i].Live()==true)
            enemy[i].draw(&painter);
        else if(enemy[i].dead==true)
        {
            Money+=100+(m_waves*10);
            enemy[i].dead=false;
        }
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    if(abs(pressPos.x()-c.x())<5&&abs(pressPos.y()-c.y())<5&&canBuy())
    {

       t=rand()%100;
       _c.getType(t);
       _c.getFigure();
       _c.build();
       flag=true;
       Money-=500;
        update();
     }
    for (int i=0;i<16;i++) {
        if(pos[i].Pointcontained(pressPos)==true&&pos[i].poetexitd()==false&&flag==true)
        {
            poet[i].getType(t);
            poet[i].getFigure();
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
void MainWindow::timerEvent(QTimerEvent *event)
{
    if(Num>=2*WAVE)
    waveLoad();
    if(event->timerId()==id3&&timstart==false)
    {
        timstart=true;
    }
    if(event->timerId()==id2&&timstart==true&&Num<2*WAVE){
        enemy[Num].t=0;
        enemy[Num].birth();

        enemy[Num+1].t=1;
        enemy[Num+1].birth();
        Num+=2;
    }
    else if(event->timerId()==id1)
    {
        for(int i=0;i<2*WAVE;i++)
            if(enemy[i].Live())
                    enemy[i].move();
    }
    if(event->timerId()==id4)
    {
        for(int i=0;i<16;i++)
        {
            if(poet[i].existed())
            {
                poet[i].chooseEnemy(enemy);
                if(poet[i].hastarget==true)
                {
                   poet[i].loseEnemy();
                }
            }
        }
        update();
   }
    update();
}
void MainWindow::waveLoad()
{

    if(m_waves>WAVE)
        game_win=true;
    else {
        int l;
        for(l=0;l<2*WAVE;l++)
        {
            if(enemy[l].Live()==true)
                break;
        }
        if(l>=2*WAVE)
        {
            timstart=false;
            for(int i=0;i<2*WAVE;i++)
            {
                enemy[i].t=i%2;
                enemy[i].updata();
            }
            Num=0;
            ++m_waves;
        }
    }
}
bool MainWindow::canBuy()
{
    if(Money>=500)
        return true;
    return false;
}
void MainWindow::drawMoney(QPainter *painter)
{
    painter->setPen(QPen(Qt::black));
    painter->drawText(QRect(200,5,200,25),QString("g:%1").arg(Money));
}
