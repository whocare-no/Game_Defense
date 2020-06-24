#include "game_bullet.h"

game_bullet::game_bullet(QPoint s,QPoint t,game_enemy *enemy,int atk):startPos(s),targetPos(t),damage(atk),target(enemy)
{

    setCurrentPos(startPos);
    figure.load("../Defense_Game/Resource/1.png");
    music=new QMediaPlayer();
    music->setMedia(QUrl("../Defense_Game/Resource/bullet.mp3"));
}
void game_bullet::draw(QPainter *painter)
{
    painter->save();
    static const QPoint offsetPoint(-10, -26);
    painter->translate(m_currentPos);
    painter->drawPixmap(offsetPoint,figure);
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
    if(target->Live()==true)
    {
        target->getAttacked(damage);
        music->play();
    }


}
QPoint game_bullet::getTargetPos()
{
    return targetPos;
}
