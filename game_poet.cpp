#include "game_poet.h"
#include"ui_mainwindow.h"
#include"mainwindow.h"
#include<QLabel>


game_poet::game_poet(QObject *parent):QObject (parent)
{
    existence=false;

    rangedrawed=false;

    m_fireRateTimer = new QTimer(this);
    srand(unsigned (time(nullptr)));
    connect(m_fireRateTimer, SIGNAL(timeout()), this, SLOT(shootWeapon()));


}
void game_poet::getPro(int dif)
{
    if(dif==1)
    {
        Pro11=3;
        Pro12=8;
        Pro13=8;
    }
    else if(dif==2)
    {
        Pro11=2;
        Pro12=7;
        Pro13=10;
    }
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
    if(type>=0&&type<1*Pro11)
    {
        Figure.load("../Defense_Game/Resource/01.png");
        Range=70;
        Damage=21;
        c_Damage=Damage;
        Rate=900;
        c_Rate=Rate;
        exp=200;
        Crit=100;
        effect=1;
        name="李白";
    }
    else if(type>=1*Pro11&&type<2*Pro11)
    {
        Figure.load("../Defense_Game/Resource/02.png");
        Range=100;
        Damage=35;
        c_Damage=Damage;
        Rate=1200;
        c_Rate=Rate;
        exp=200;
        Crit=0;
        effect=4;
        name="郭嘉";
    }
    else if(type>=2*Pro11&&type<3*Pro11)
    {
        Figure.load("../Defense_Game/Resource/03.png");
        Range=80;
        Damage=25;
        c_Damage=Damage;
        Rate=1000;
        c_Rate=Rate;
        exp=200;
        Crit=0;
        effect=2;
        Effectrate=100;
        name="杜甫";
    }
    else if(type>=3*Pro11&&type<4*Pro11)
    {
        Figure.load("../Defense_Game/Resource/04.png");
        Range=80;
        Damage=25;
        c_Damage=Damage;
        Rate=1000;
        c_Rate=Rate;
        exp=200;
        Crit=0;
        effect=3;
        Effectrate=100;
        name="李清照";
    }
    else if(type>=4*Pro11&&type<4*Pro11+1*Pro12)
    {
        Figure.load("../Defense_Game/Resource/05.png");
        Range=80;
        Damage=15;
        c_Damage=Damage;
        Rate=1000;
        c_Rate=Rate;
        Crit=60;
        exp=150;
        effect=1;
        name="苏轼";
    }
    else if(type>=4*Pro11+1*Pro12&&type<4*Pro11+2*Pro12)
    {
        Figure.load("../Defense_Game/Resource/06.png");
        Range=80;
        Damage=21;
        c_Damage=Damage;
        Rate=1000;
        c_Rate=Rate;
        Crit=0;
        exp=150;
        effect=4;
        name="辛弃疾";
    }
    else if(type>=4*Pro11+2*Pro12&&type<4*Pro11+3*Pro12)
    {
        Figure.load("../Defense_Game/Resource/07.png");
        Range=80;
        Damage=18;
        c_Damage=Damage;
        Rate=1000;
        c_Rate=Rate;
        Crit=0;
        exp=150;
        effect=2;
        Effectrate=60;
        name="屈原";
    }
    else if(type>=4*Pro11+3*Pro12&&type<4*Pro11+4*Pro12)
    {
        Figure.load("../Defense_Game/Resource/08.png");
        Range=80;
        Damage=18;
        c_Damage=Damage;
        Rate=1000;
        c_Rate=Rate;
        Crit=0;
        exp=150;
        effect=3;
        Effectrate=60;
        name="薛涛";
    }
    else if(type>=4*Pro11+4*Pro12&&type<4*Pro11+4*Pro12+1*Pro13)
    {
        Figure.load("../Defense_Game/Resource/09.png");
        Range=80;
        Damage=12;
        c_Damage=Damage;
        Rate=1000;
        c_Rate=Rate;
        Crit=30;
        exp=100;
        effect=1;
        name="柳永";
    }
    else if(type>=4*Pro11+4*Pro12+1*Pro13&&type<4*Pro11+4*Pro12+2*Pro13)
    {
        Figure.load("../Defense_Game/Resource/10.png");
        Range=80;
        Damage=17;
        c_Damage=Damage;
        Rate=1000;
        c_Rate=Rate;
        Crit=0;
        exp=100;
        effect=4;
        name="潘安";
    }
    else if(type>=4*Pro11+4*Pro12+2*Pro13&&type<4*Pro11+4*Pro12+3*Pro13)
    {
        Figure.load("../Defense_Game/Resource/11.png");
        Range=80;
        Damage=15;
        c_Damage=Damage;
        Rate=1000;
        c_Rate=Rate;
        exp=100;
        Crit=0;
        effect=2;
        Effectrate=30;
        name="鱼玄机";
    }
    else if(type>=4*Pro11+4*Pro12+3*Pro13&&type<4*Pro11+4*Pro12+4*Pro13)
    {
        Figure.load("../Defense_Game/Resource/12.png");
        Range=80;
        Damage=15;
        c_Damage=Damage;
        Rate=1000;
        c_Rate=Rate;
        exp=100;
        Crit=0;
        effect=3;
        Effectrate=30;
        name="小乔";
    }
    else if(type>=76&&type<=88)
    {
        Figure.load("../Defense_Game/Resource/15.png");
        exp=100;
        name="玉女";
    }
    else if(type>=89&&type<=99)
    {
        Figure.load("../Defense_Game/Resource/14.png");
        exp=100;
        name="金童";
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
                 if(getLength(&enemy[i])<=Range&&enemy[i].INViNCIBILITY==false)
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
    m_fireRateTimer->start(c_Rate);
    Effect(target);
}
void game_poet::shootWeapon()
{
    int t=rand()%100;
    game_bullet *bullet;
    if(t<Crit)
        bullet = new game_bullet(this->pos,target->getPos(),this->target,2*this->c_Damage);
    else {
        bullet = new game_bullet(this->pos,target->getPos(),this->target,this->c_Damage);
    }
    m_bullet.push_back(bullet);

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
    QFont ft;
    ft.setPointSize(4);

    painter->save();
    if(type<4*Pro11)
        painter->setPen(Qt::red);
    else if(type<4*Pro11+4*Pro12)
        painter->setPen(Qt::yellow);
    else
        painter->setPen(Qt::blue);
    painter->translate(pos+QPoint(20,-40));

    painter->setFont(ft);
    QTextOption option(Qt::AlignCenter);
    option.setWrapMode(QTextOption::WordWrap);
    painter->drawText(QRect(0,0,12,40),name);
    painter->restore();

    painter->save();
    painter->setPen(Qt::yellow);
    painter->translate(pos+QPoint(20,-50));
    painter->setFont(ft);
    painter->drawText(0,0,QString::number(level));
    painter->restore();


    painter->save();
    static const QPoint offsetPoint(-Figure.width()/2, -Figure.height()+6);
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
void game_poet::drawData(QPainter *painter)
{
    QFont ft;
    ft.setPointSize(5);
    QPoint p(250,290);

    painter->setFont(ft);
    painter->drawText(p-QPoint(0,14),"姓名");
    painter->drawText(p+QPoint(30,-14),name);
    painter->drawText(p,"攻击力");
    painter->drawText(p+QPoint(30,0),QString::number(c_Damage));

    painter->drawText(p+QPoint(0,14),"攻速");
    painter->drawText(p+QPoint(30,14),QString::number(c_Rate/1000.0));
    QString string;
    if(effect==2)
        string="能力：有"+QString::number(Effectrate)+"几率使敌人定身";
    else if(effect==3)
        string="能力：有"+QString::number(Effectrate)+"几率使敌人闪避率减半";
    else if(effect==1)
        string="能力：有"+QString::number(Crit)+"几率暴击";
    painter->drawText(p+QPoint(0,28),string);
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
int game_poet::getExp()
{
    return exp;
}
void game_poet::levelup()
{
    ++level;
}
void game_poet::getDamage()
{
    int temp;
    if(type<4*Pro11)
        temp=5;
    else if(type<4*Pro11+4*Pro12)
        temp=4;
    else
        temp=3;
    Damage+=level*temp*effect;
    c_Damage=Damage;


}
int game_poet::getLevel()
{
    return level;
}
void game_poet::Effect(game_enemy *target)
{
    int temp=rand()%100;
    if(effect==2&&temp<=Effectrate)
    {
        if(target->t==1)
        {
            target->changeFigure("../Defense_Game/Resource/31.png");
            target->changeSp();
        }

        else if(target->t==0) {
            target->changeFigure("../Defense_Game/Resource/32.png");
            target->changeSp();
        }
        else if(target->t==2) {
            target->changeFigure("../Defense_Game/Resource/33.png");
            target->changeSp();
        }
        else if(target->t==3) {
            target->changeFigure("../Defense_Game/Resource/34.png");
            target->changeSp();
        }

    }
    else if (effect==3&&temp<=Effectrate) {

        if(target->t==1)
        {
            target->changeFigure("../Defense_Game/Resource/41.png");
            target->changede();
        }

        else if(target->t==0) {
            target->changeFigure("../Defense_Game/Resource/42.png");
            target->changede();
        }
        else if(target->t==2) {
            target->changeFigure("../Defense_Game/Resource/43.png");
            target->changede();
        }
        else if(target->t==3) {
            target->changeFigure("../Defense_Game/Resource/44.png");
            target->changede();
        }
    }
}

void game_poet::getaEffect(int t1, int l2,int l1)
{
    c_Rate=Rate-50*t1-10*(l1-t1);
    c_Damage=Damage*(100+l2*5);
    c_Damage=c_Damage/100;
}
