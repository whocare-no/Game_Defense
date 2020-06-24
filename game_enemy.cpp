#include "game_enemy.h"

game_enemy::game_enemy(QObject *parent) :
    QObject(parent)
{

    entrance[0]=QPoint(425,150);
    entrance[1]=QPoint(425,170);
    exit=QPoint(60,160);
    max_hp=40;
    current_hp=40;
    sp=5;
    de=0;
    srand(unsigned (time(nullptr)));

}

void game_enemy::draw(QPainter *painter)
{
    static const int Health_Bar_Width = 40;
    painter->save();
    if(current_hp<0)
        current_hp=0;
    QPoint healthBarPoint = m_pos + QPoint(-10, -3);
    // 绘制血条
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect healthBarBackRect(healthBarPoint, QSize(Health_Bar_Width, 3));
    painter->drawRect(healthBarBackRect);
    painter->setBrush(Qt::green);
    QRect healthBarRect(healthBarPoint, QSize((double) current_hp/ max_hp * Health_Bar_Width, 3));
    painter->drawRect(healthBarRect);

    static const QPoint offsetPoint(-10,-60);
    painter->translate(m_pos);

    painter->drawPixmap(offsetPoint, m_figure);
    painter->restore();

}
QPoint game_enemy::getPos()const
{
    return m_pos;
}
void game_enemy::birth()
{
    enemyLive=true;
    m_pos=entrance[t%2];
    if(t==1)
    {
         m_figure.load("../Defense_Game/Resource/21.png");
         dod=5+wave*2;

    }
    else if(t==0)
    {
         m_figure.load("../Defense_Game/Resource/22.png");
         dod=wave*1;
         max_hp=80;
         current_hp=80;
    }
    else if(t==2)
    {
         m_figure.load("../Defense_Game/Resource/23.png");
         dod=3+wave*2;
    }
    else if(t==3)
    {
         m_figure.load("../Defense_Game/Resource/24.png");
         dod=wave*1;
         max_hp=50;
         current_hp=50;
    }

}
void game_enemy::drawEffect(QPainter *painter)
{
    if(effectflag==true&&t==1)
    {
        QPixmap h;
        h.load("../Defense_Game/Resource/61.png");
        painter->drawPixmap(m_pos-QPoint(50,40),h);
    }    
    if(effectflag==true&&t==0)
    {
        QPixmap h;
        h.load("../Defense_Game/Resource/62.png");
        painter->drawPixmap(m_pos-QPoint(20,70),h);
    }
}
void game_enemy::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==id1)
      {
        effectflag=false;
        INViNCIBILITY=false;
        de=0;
    }

}
bool game_enemy::Live()
{
    return enemyLive;
}
void game_enemy::death()
{
    if(current_hp<=0)
    {
     enemyLive=false;
     dead=true;
     effectflag=false;
    }

}
void game_enemy::move()
{
    if(m_pos.x()<=exit.x())
    {
        enemyMiss=true;
        enemyLive=false;
    }
    else {
        int movementSpeed = sp;
        m_pos= m_pos-QPoint(movementSpeed,0);

    }
}
void game_enemy::getAttacked(int atk)
{
    int temp=rand()%100;
    if(temp>dod)
    {
        if(atk<de)
            de=atk;
        current_hp-=(atk-de);
    }

    if(current_hp<=0)
    {
        enemyLive=false;
        dead=true;
    }


}
void game_enemy::updata()
{
    m_pos=entrance[t];
    dead=false;
    current_hp=max_hp;
    INViNCIBILITY=false;
    sp=5;


}
void game_enemy::getWaves(int m_wave)
{
    wave=m_wave;   
    max_hp=max_hp*wave;
}
void game_enemy::changeFigure(QString a)
{
    m_figure.load(a);
}
void game_enemy::changeSp()
{
    sp=0;
}
void game_enemy::changede()
{
    dod=dod/2;
}
void game_enemy::Effect()
{
    if(5*current_hp<=max_hp&&effect==true)
    {
        de=99999;
        id1=startTimer(15000);
        effect=false;
        effectflag=true;
        INViNCIBILITY=true;
    }

}
void game_enemy::Effect(game_enemy enemy[40])
{
    int num=0;
    if(effect==true)
    {
        for(int i=0;i<40;i++)
        {
            if(enemy[i].Live()==true&&2*enemy[i].current_hp<max_hp&&getLength(enemy[i].getPos())<=2500)
                num++;
        }
    }

    if(num>=3)
    {
        for(int i=0;i<40;i++)
        {
            if(enemy[i].Live()==true&&2*enemy[i].current_hp<max_hp&&getLength(enemy[i].getPos())<=2500)
            {

                enemy[i].current_hp+=(max_hp/2);

            }

        }
        id1=startTimer(3000);

        effect=false;
        effectflag=true;
    }
}
int game_enemy::getLength(QPoint pos)const
{
    return (m_pos.x()-pos.x())*(m_pos.x()-pos.x())+(m_pos.y()-pos.y())*(m_pos.y()-pos.y());
}
