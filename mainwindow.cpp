#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

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
    QMediaPlayer *music1 =new QMediaPlayer();
    music1->setMedia(QUrl("../Defense_Game/Resource/music1.mp3"));
    music1->play();
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
    drawMoney();
    drawExp();
    QPixmap map;
    map.load("../Defense_Game/Resource/map.png");
    painter.drawPixmap(0,0,map);    
    if(_c.existed()==true)
        _c.drawPoet(&painter);
    for (int i=0;i<16;i++) {
        if(pos[i].poetexitd()==true&&poet[i].existed()==true)
        poet[i].drawPoet(&painter);
    }
    for(int i=0;i<16;i++)
    {
        if(poet[i].existed()==true&&poet[i].poetdrawed==true)
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

    if(event->button()==Qt::LeftButton&&abs(pressPos.x()-c.x())<5&&abs(pressPos.y()-c.y())<5&&canBuy())
    {
       if(flag==true)
           Exp+=_c.getExp();
       t=rand()%100;
       _c.getType(t);
       _c.getFigure();
       _c.build();
       flag=true;
       Money-=500;
        update();
     }
    for (int i=0;i<16;i++) {
        if(event->button()==Qt::LeftButton&&pos[i].Pointcontained(pressPos)==true&&pos[i].poetexitd()==false&&flag==true)
        {
            poet[i].getType(t);
            poet[i].getFigure();
            poet[i].build();
            pos[i].getExistence(true);
            _c.unbuild();
            flag=false;
            update();
        }
        else if(event->button()==Qt::LeftButton&&pos[i].Pointcontained(pressPos)==true&&pos[i].poetexitd()==true&&poet[i].poetdrawed==false)
        {
            poet[i].poetdrawed=true;
            update();
        }
        else if(event->button()==Qt::LeftButton&&pos[i].Pointcontained(pressPos)==true&&pos[i].poetexitd()==true&&poet[i].poetdrawed==true)
        {
            poet[i].poetdrawed=false;
            update();
        }
        else if(event->button()==Qt::RightButton&&pos[i].Pointcontained(pressPos)==true&&pos[i].poetexitd()==true)
        {
            poet[i].unbuild();
            pos[i].getExistence(false);
            Exp+=poet[i].getExp();
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
void MainWindow::drawMoney()
{
    QFont ft;
    ft.setPointSize(6);
    QPalette label_pe;
    label_pe.setColor(QPalette::WindowText, Qt::yellow);
    ui->label->setPalette(label_pe);
    ui->label->setGeometry(309,232,30,9);
    ui->label->setFont(ft);
    ui->label->setNum(Money);
}
void MainWindow::drawExp()
{
    QFont ft,ft1;
    ft.setPointSize(7);
    ft1.setPointSize(7);
    QPalette label_pe;
    label_pe.setColor(QPalette::WindowText, Qt::blue);
    ui->label_e->setPalette(label_pe);
    ui->label_e->setGeometry(70,0,30,9);
    ui->label_e->setFont(ft);
    ui->label_->setFont(ft1);
    ui->label_->setPalette(label_pe);
    ui->label_->setGeometry(40,0,40,12);
    ui->label_->setText("Exp:");
    ui->label_e->setNum(Exp);
}
