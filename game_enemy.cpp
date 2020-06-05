#include "game_enemy.h"

game_enemy::game_enemy(QObject *parent) :
    QObject(parent)
{

    entrance[0]=QPoint(425,150);
    entrance[1]=QPoint(425,170);
    exit=QPoint(60,160);
    max_hp=40;
    current_hp=40;
    sp=2;


}
void game_enemy::draw(QPainter *painter)
{
    // 血条的长度
    // 其实就是2个方框,红色方框表示总生命,固定大小不变
    // 绿色方框表示当前生命,受m_currentHp / m_maxHp的变化影响
    static const int Health_Bar_Width = 40;
    painter->save();
    QPoint healthBarPoint = m_pos + QPoint(-10, -3);
    // 绘制血条
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect healthBarBackRect(healthBarPoint, QSize(Health_Bar_Width, 3));
    painter->drawRect(healthBarBackRect);
    painter->setBrush(Qt::green);
    QRect healthBarRect(healthBarPoint, QSize((double) current_hp/ max_hp * Health_Bar_Width, 3));
    painter->drawRect(healthBarRect);
    // 绘制偏转坐标,由中心+偏移=左上
    static const QPoint offsetPoint(-10,-60);
    painter->translate(m_pos);
    //painter->rotate(m_rotationSprite);
    // 绘制敌人
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
    m_pos=entrance[t];
    if(t==1)
    m_figure.load("../Defense_Game/Resource/11.png");
    else if(t==0)
        m_figure.load("../Defense_Game/Resource/08.png");
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
    if(current_hp<=0)
    {
        enemyLive=false;
        dead=true;
    }
    else
        current_hp-=atk;
}
void game_enemy::updata()
{
    m_pos=entrance[t];
    dead=false;
    current_hp=max_hp;
}
