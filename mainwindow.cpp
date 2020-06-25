#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

#define WAVE 20

MainWindow::MainWindow(int t,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),c(386,281),Dificulty(t)
{
    ui->setupUi(this);
    end=new class game_end(true);
    poetgetPos();
    _c.getPro(Dificulty);
    for(int i=0;i<16;i++)
        poet[i].getPro(Dificulty);
    srand(unsigned (time(nullptr)));    
    id1=startTimer(500);
    id2=startTimer(3000);
    id3=startTimer(30000);
    id4=startTimer(10);
    id5=startTimer(220000);
    music1 =new QMediaPlayer();
    music2 =new QMediaPlayer();
    music1->setMedia(QUrl("../Defense_Game/Resource/bgm.mp3"));
    music2->setMedia(QUrl("../Defense_Game/Resource/gold.mp3"));
    music1->play();

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::poetgetPos()
{
    _c.setPos(QPoint(100,318));
    ac.setPos(QPoint(100,318));
    for(int i=0;i<16;i++)
    {
        poet[i].setPos(pos[i].getPos());
        aux[i].setPos(pos[i].getPos());
    }

}
void MainWindow::paintEvent(QPaintEvent *)
{
    if(game_end==true||game_win==true)
    {
        QPainter painter(this);

        if(game_win==true)
            end=new class game_end(true);
        else
            end=new class game_end(false);
        this->setAttribute(Qt::WA_DeleteOnClose,1);
        this->close();
        end->show();

    }

    QPainter painter(this);
    QPixmap map;
    map.load("../Defense_Game/Resource/map.png");
    QPainter pluspainter(&map);

    if(_c.existed()==true)
        _c.drawPoet(&pluspainter);
    if(ac.existed()==true)
        ac.drawPoet(&pluspainter);
    for (int i=0;i<16;i++) {
        if(pos[i].poetexitd()==true&&poet[i].existed()==true)
        poet[i].drawPoet(&pluspainter);
        else if (pos[i].poetexitd()==true&&aux[i].existed()==true) {
            aux[i].drawPoet(&pluspainter);
        }
    }

    for(int i=0;i<16;i++)
    {
        if (aux[i].existed()==true&&aux[i].rangedrawed==true)
            aux[i].drawData(&pluspainter);
        else if(poet[i].existed()==true)
        {
            if(poet[i].rangedrawed==true)
            {
                poet[i].drawRange(&pluspainter);
                poet[i].drawData(&pluspainter);
            }
            poet[i].chooseEnemy(enemy);
            auxEffectload();
            poet[i].getaEffect(t1[i],l2[i],l1[i]);
            if(poet[i].hastarget==true)
            {
                poet[i].drawBullet(&pluspainter);
            }
        }
    }
    painter.drawPixmap(0,0,map);
    for(int i=0;i<2*WAVE;i++)
    {

        if(enemy[i].Live()==true)
        {
            enemy[i].draw(&painter);
            enemy[i].drawEffect(&painter);
            if(enemy[i].t==1)
                enemy[i].Effect(enemy);
            else if(enemy[i].t==0)
                enemy[i].Effect();

        }
        else if (enemy[i].enemyMiss==true) {
            missnum++;
            if(missnum>=20)
                game_end=true;
            enemy[i].enemyMiss=false;
        }
        else if(enemy[i].dead==true)
        {
            music2->play();
            Money+=100+m_waves*10-50*(Dificulty-1);
            enemy[i].dead=false;
        }

    }

    drawMoney(&painter);
    drawExp(&painter);
    drawMissNum(&painter);
    drawWaves(&painter);

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();

    if(event->button()==Qt::LeftButton&&abs(pressPos.x()-c.x())<5&&abs(pressPos.y()-c.y())<5&&canBuy())
    {
       if(flag==true&&_c.existed())
       {
           Exp+=_c.getExp();
           _c.unbuild();
       }
       else if(flag==true&&ac.existed())
       {
           Exp+=ac.getExp();
           ac.unbuild();
       }

       t=rand()%100;
       if(t<76)
       {
           _c.getType(t);
           _c.getFigure();
           _c.build();

       }
       else {
           ac.getType(t);
           ac.getFigure();
           ac.build();
       }
       flag=true;
       Money-=500;
        update();
     }
    for (int i=0;i<16;i++) {
        if(event->button()==Qt::LeftButton&&pos[i].Pointcontained(pressPos)==true&&pos[i].poetexitd()==false&&flag==true)
        {
            if(t<76)
            {
                poet[i].getType(t);
                poet[i].getFigure();
                poet[i].build();
                _c.unbuild();
            }
            else {
                aux[i].getType(t);
                aux[i].getFigure();
                aux[i].build();

                ac.unbuild();
            }
            pos[i].getExistence(true);

            flag=false;
            update();
        }
        else if(event->button()==Qt::LeftButton&&pos[i].Pointcontained(pressPos)==true&&poet[i].existed()==true&&poet[i].rangedrawed==false)
        {
            poet[i].rangedrawed=true;
            update();
        }
        else if(event->button()==Qt::LeftButton&&pos[i].Pointcontained(pressPos)==true&&aux[i].existed()==true&&aux[i].rangedrawed==false)
        {
            aux[i].rangedrawed=true;
            update();
        }
        else if(event->button()==Qt::LeftButton&&pos[i].Pointcontained(pressPos)==true&&poet[i].existed()==true&&poet[i].rangedrawed==true)
        {
            poet[i].rangedrawed=false;
            update();
        }
        else if(event->button()==Qt::LeftButton&&pos[i].Pointcontained(pressPos)==true&&aux[i].existed()==true&&aux[i].rangedrawed==true)
        {
            aux[i].rangedrawed=false;
            update();
        }
        else if(event->button()==Qt::RightButton&&pos[i].Pointcontained(pressPos)==true&&pos[i].poetexitd()==true)
        {
            if(poet[i].existed())
            {
                poet[i].unbuild();
                pos[i].getExistence(false);
                Exp+=poet[i].getExp()*poet[i].getLevel();
            }
            else
            {
                aux[i].unbuild();
                pos[i].getExistence(false);
                Exp+=aux[i].getExp()*poet[i].getLevel();
            }
        }
    }
}
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    for(int i=0;i<16;i++)
    {
        if(pos[i].Pointcontained(pressPos)==true&&poet[i].existed()==true&&Exp>=poet[i].getExp())
        {
            if(poet[i].getLevel()<16)
            {
                poet[i].levelup();
                poet[i].getDamage();
                Exp-=poet[i].getExp();
                update();
            }
        }
        else if (pos[i].Pointcontained(pressPos)==true&&aux[i].existed()==true&&Exp>=aux[i].getExp()) {
            if(aux[i].getLevel()<10)
            {
                aux[i].levelup();
                Exp-=aux[i].getExp();
                update();
            }
        }
    }
}
void MainWindow::timerEvent(QTimerEvent *event)
{
    if(Num>=2*WAVE)
    waveLoad();
    if(event->timerId()==id5)
        music1->play();
    if(event->timerId()==id3&&timstart==false)
    {
        timstart=true;
    }
    if(event->timerId()==id2&&timstart==true&&Num<2*WAVE){
        int tt=rand()%10;
        if(tt<=m_waves)
        {
            if(Num%4==2)
            {
                enemy[Num].t=0;
                enemy[Num].birth();
                enemy[Num+1].t=1;
                enemy[Num+1].birth();
                Num+=2;
            }
            else
            {
                enemy[Num].t=1;
                enemy[Num].birth();
                enemy[Num+1].t=0;
                enemy[Num+1].birth();
                Num+=2;
            }

        }
        else
        {

            enemy[Num].t=2;
            enemy[Num].birth();
            enemy[Num+1].t=3;
            enemy[Num+1].birth();
            Num+=2;
        }

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
                if(poet[i].hastarget==true)
                {
                   poet[i].loseEnemy();
                }
                poet[i].chooseEnemy(enemy);

            }
        }
        update();
   }
    update();
}
void MainWindow::waveLoad()
{

    if(m_waves>WAVE/2)
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
            ++m_waves;
            for(int i=0;i<2*WAVE;i++)
            {
                enemy[i].getWaves(m_waves);
                enemy[i].updata();
            }
            Num=0;

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
    QFont ft;
    ft.setPointSize(6);
    QPoint p(315,257);
    painter->setFont(ft);
    painter->setPen(Qt::yellow);
    painter->drawText(p,QString::number(Money));
}
void MainWindow::drawExp(QPainter *painter)
{
    QFont ft;
    ft.setPointSize(7);    
    QPoint p(30,15);
    painter->setFont(ft);
    painter->setPen(Qt::blue);


    painter->drawText(p,"Exp:"+QString::number(Exp));

}
void MainWindow::drawMissNum(QPainter *painter)
{
    QFont ft;
    ft.setPointSize(7);
    QPoint p(346,18);

    painter->setPen(Qt::yellow);
    painter->setFont(ft);
    painter->drawText(p,QString::number(missnum)+"/20");
}
void MainWindow::drawWaves(QPainter *painter)
{
    QFont ft;
    ft.setPointSize(7);
    painter->setPen(Qt::yellow);
    painter->setFont(ft);
    QPoint p(179,18);
    painter->drawText(p,QString::number(m_waves));
}
void MainWindow::auxEffectload()
{
    for(int i=0;i<16;i++)
    {

        t1[i]=0;l1[i]=0;l2[i]=0;
    }
    for(int i=0;i<16;i++)
    {
        int temp[8]={-1,1,3,4,5,-3,-4,-5};
        if(aux[i].existed()==true&&i<8)
        {
            for(int j=0;j<8;j++)
            {
                if(0<=i+temp[j]&&i+temp[j]<8&&poet[i+temp[j]].existed())
                {
                    if(aux[i].Type()==1)
                    {
                        t1[i+temp[j]]++;
                        l1[i+temp[j]]+=aux[i].getLevel();

                    }
                    else
                        l2[i+temp[j]]+=aux[i].getLevel();

                }

            }
        }
        else if(aux[i].existed()==true&&i>7){
            for(int j=0;j<8;j++)
            {
                if(8<=i+temp[j]&&i+temp[j]<16&&poet[i+temp[j]].existed())
                {
                    if(aux[i].Type()==1)
                    {
                        t1[i+temp[j]]++;
                        l1[i+temp[j]]+=aux[i].getLevel();
                    }
                    else
                        l2[i+temp[j]]+=aux[i].getLevel();

                }
            }
        }
    }
}
