#include "game_enemy.h"

game_enemy::game_enemy(int t,MainWindow *game,QObject *parent) :
    QObject(parent),type(t),m_game(game)
{
    entrance=QPoint(425,160);
    exit=QPoint(60,160);
    max_hp=40;
    current_hp=40;
    m_figure.load("../Defense_Game/Resource/02.png");
}
void game_enemy::draw(QPainter *painter)
{
    // 血条的长度
    // 其实就是2个方框,红色方框表示总生命,固定大小不变
    // 绿色方框表示当前生命,受m_currentHp / m_maxHp的变化影响
    static const int Health_Bar_Width = 20;
    painter->save();
    QPoint healthBarPoint = m_pos + QPoint(-Health_Bar_Width / 2 - 5, -3);
    // 绘制血条
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect healthBarBackRect(healthBarPoint, QSize(Health_Bar_Width, 2));
    painter->drawRect(healthBarBackRect);
    painter->setBrush(Qt::green);
    QRect healthBarRect(healthBarPoint, QSize((double) current_hp/ max_hp * Health_Bar_Width, 2));
    painter->drawRect(healthBarRect);
    // 绘制偏转坐标,由中心+偏移=左上
    static const QPoint offsetPoint(-10,-20);
    painter->translate(m_pos);
    //painter->rotate(m_rotationSprite);
    // 绘制敌人
    painter->drawPixmap(offsetPoint, m_figure);
    painter->restore();

}
