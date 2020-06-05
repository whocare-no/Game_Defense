#include "game_poet.h"
#include"ui_mainwindow.h"
#include"mainwindow.h"
#include<QLabel>
game_poet::game_poet(QObject *parent):QObject (parent)
{
    existence=false;

    poetdrawed=false;

    m_fireRateTimer = new QTimer(this);
    connect(m_fireRateTimer, SIGNAL(timeout()), this, SLOT(shootWeapon()));
}
bool game_poet::existed()
{
    return existence;
}
void game_poet::build()
{
    existence=true;
}
void game_poet::unbuild()
{
    existence=false;
}
void game_poet::getType(int t)
{
    type=t;
}
void game_poet::getFigure()
{
    if(type>=0&&type<=2)
    {
        Figure.load("../Defense_Game/Resource/01.png");
        Range=80;
        Damage=7;
        Rate=200;
    }
    else if(type>=3&&type<=5)
    {
        Figure.load("../Defense_Game/Resource/02.png");
        Range=120;
        Damage=10;
        Rate=500;
    }
    else if(type>=6&&type<=8)
    {
        Figure.load("../Defense_Game/Resource/03.png");
        Range=100;
        Damage=5;
        Rate=350;
    }
    else if(type>=9&&type<=11)
    {
        Figure.load("../Defense_Game/Resource/03.png");
        Range=100;
        Damage=5;
        Rate=350;
    }
    else if(type>=12&&type<=14)
    {
        Figure.load("../Defense_Game/Resource/04.png");
        Range=100;
        Damage=5;
        Rate=350;
    }
    else if(type>=15&&type<=24)
    {
        Figure.load("../Defense_Game/Resource/05.png");
        Range=100;
        Damage=5;
        Rate=350;
    }
    else if(type>=25&&type<=35)
    {
        Figure.load("../Defense_Game/Resource/06.png");
        Range=100;
        Damage=5;
        Rate=350;
    }
    else if(type>=36&&type<=47)
    {
        Figure.load("../Defense_Game/Resource/07.png");
        Range=100;
        Damage=5;
        Rate=350;
    }
    else if(type>=48&&type<=57)
    {
        Figure.load("../Defense_Game/Resource/08.png");
        Range=100;
        Damage=5;
        Rate=350;
    }
    else if(type>=58&&type<=64)
    {
        Figure.load("../Defense_Game/Resource/09.png");
        Range=100;
        Damage=5;
        Rate=350;
    }
    else if(type>=65&&type<=71)
    {
        Figure.load("../Defense_Game/Resource/10.png");
        Range=100;
        Damage=5;
        Rate=350;
    }
    else if(type>=72&&type<=78)
    {
        Figure.load("../Defense_Game/Resource/11.png");
        Range=100;
        Damage=5;
        Rate=350;
    }
    else if(type>=79&&type<=85)
    {
        Figure.load("../Defense_Game/Resource/12.png");
        Range=100;
        Damage=5;
        Rate=350;
    }
    else if(type>=86&&type<=93)
    {
        Figure.load("../Defense_Game/Resource/15.png");
        Range=100;
        Damage=5;
        Rate=350;
    }
    else if(type>=94&&type<=99)
    {
        Figure.load("../Defense_Game/Resource/14.png");
        Range=100;
        Damage=5;
        Rate=350;
    }
}
void game_poet::setPos(QPoint x)
{
    pos=x;
}
double game_poet::getLength(game_enemy *enemy)
{
    double s=sqrt((pos.x()-enemy->getPos().x())*(pos.x()-enemy->getPos().x())+(pos.y()-enemy->getPos().y())*(pos.y()-enemy->getPos().y()));
    return s;
}
void game_poet::chooseEnemy(game_enemy enemy[40])
{
    if(this->existed()&&hastarget==false)
    {
       for(int i=0;i<40;i++)
       {
           if(enemy[i].Live())
           {
                 if(getLength(&enemy[i])<=Range)
                 {
                    target=&enemy[i];
                    hastarget=true;
                    attakEnemy();
                     break;
                 }

              }
        }
      }

}
void game_poet::attakEnemy()
{
    m_fireRateTimer->start(Rate);
}
void game_poet::shootWeapon()
{
    game_bullet *bullet = new game_bullet(this->pos,target->getPos(),this->target);
    m_bullet.push_back(bullet);
    //bullet->draw(painter);
    bullet->move();

}
void game_poet::drawRange(QPainter *painter)
{

    painter->setPen(Qt::blue);
    // 绘制攻击范围
    painter->drawEllipse(pos,Range, Range);
}
void game_poet::drawPoet(QPainter *painter)
{
    painter->save();
    // 绘制炮塔并选择炮塔
    // 这里将坐标原点移到m_pos,绘制的适合,就要加上那个偏移点到左上角
    static const QPoint offsetPoint(-20, -51);
    painter->translate(pos);
    painter->drawPixmap(offsetPoint, Figure);
    painter->restore();
}
void game_poet::drawBullet(QPainter *painter)
{
    foreach(game_bullet *bullet,m_bullet)
    {
        bullet->draw(painter);
        if(bullet->currentPos()==bullet->getTargetPos())
        m_bullet.removeOne(bullet);
    }

}
void  game_poet::loseEnemy()
{
    if(target->Live()==false)
    {
        hastarget=false;
        m_fireRateTimer->stop();
    }
    else if(getLength(target)>Range)
    {
        hastarget=false;
        m_fireRateTimer->stop();
    }

}
