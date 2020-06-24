#ifndef GAME_BULLET_H
#define GAME_BULLET_H
#include<QObject>
#include<QPropertyAnimation>
#include"game_enemy.h"
#include<QPoint>
#include<QPainter>
#include<QMediaPlayer>
#include<QPixmap>
class game_bullet:public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QPoint m_currentPos READ currentPos WRITE setCurrentPos)
    explicit game_bullet(QPoint s,QPoint t,game_enemy *enemy,int atk);
    //~game_bullet();
    void draw(QPainter *);
    void move();
    QPoint getTargetPos();
    QPoint currentPos();
    void setCurrentPos(QPoint pos);
signals:
    void finished();
private slots:
    void Hit();
private:
    const QPoint startPos;
    const QPoint targetPos;
    QPoint m_currentPos;
    QPixmap figure;
    int damage;
    game_enemy *target;
    QMediaPlayer *music;

};

#endif // GAME_BULLET_H
