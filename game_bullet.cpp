#include "game_bullet.h"

game_bullet::game_bullet(QPoint s,QPoint t,game_enemy *enemy):startPos(s),targetPos(t),target(enemy)
{
    damage=5;
    setCurrentPos(startPos);
    figure.load("../Defense_Game/Resource/1.png");
}
void game_bullet::draw(QPainter *painter)
{
    painter->save();
    static const QPoint offsetPoint(-10, -26);
    //painter->translate(m_currentPos);
    painter->drawPixmap(m_currentPos+offsetPoint,figure);
    painter->restore();
}
void game_bullet::setCurrentPos(QPoint pos)
{
    m_currentPos=pos;
}
QPoint game_bullet::currentPos()
{
    return m_currentPos;
}
void game_bullet::move()
{

    // 100毫秒内击中敌人
    static const int duration = 1000;
    QPropertyAnimation *animation = new QPropertyAnimation;
    animation->setTargetObject(this);
    animation->setPropertyName("m_currentPos");
    animation->setDuration(duration);
    animation->setStartValue(startPos);
    animation->setEndValue(targetPos);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(Hit()));

}

void game_bullet::Hit()
{
    target->getAttacked(damage);
    //delete this;
}
QPoint game_bullet::getTargetPos()
{
    return targetPos;
}
