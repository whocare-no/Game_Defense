#include "game_poet.h"
#include"ui_mainwindow.h"
#include"mainwindow.h"
#include<QLabel>
game_poet::game_poet(QPoint x):pos(x)
{


    existence=false;
    poetdrawed=false;

    Range=70;
}
bool game_poet::existed()
{
    return existence;
}
void game_poet::build()
{
//    QLabel *_poet = new QLabel();
//    _poet->setPixmap(Figure);
//    _poet->setFixedSize(Figure.size());
//    _poet->move(200,280);
//    _poet->show();
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
    switch(type){
       case 1:Figure.load("../Defense_Game/Resource/01.png");break;
       case 2:Figure.load("../Defense_Game/Resource/02.png");break;
       case 3:Figure.load("../Defense_Game/Resource/03.png");break;
       case 4:Figure.load("../Defense_Game/Resource/04.png");break;
       case 0:Figure.load("../Defense_Game/Resource/05.png");break;
    }
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
    static const QPoint offsetPoint(-20, -57);
    painter->translate(pos);
    painter->drawPixmap(offsetPoint, Figure);
    painter->restore();

}
