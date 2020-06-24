#include "game_auxiliary.h"

game_auxiliary::game_auxiliary()
{
    level=1;
}

void game_auxiliary::drawData(QPainter *painter)
{
    QFont ft;
    ft.setPointSize(5);
    QPoint p(250,290);
    QPoint p1(250,270);
    painter->setPen(Qt::blue);
    painter->setFont(ft);
    painter->drawText(p1,"姓名");
    painter->drawText(p1+QPoint(30,0),name);
    painter->drawText(p,"能力");
    QString po;
    if(type>88)
    {

        po="增加攻击力"+QString::number(level*5)+"%";
    }
    else
    {

        po="增快攻击速率"+QString::number(0.05+level/100.0);
    }

    painter->drawText(p+QPoint(30,0),po);
}
int game_auxiliary::Type()const
{
    if(type<89)
        return 1;
    else
        return 0;
}
