#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H
#include"mainwindow.h"
#include <QObject>
#include<QPainter>
class game_enemy : public QObject
{
    Q_OBJECT
public:
    explicit game_enemy(int t,MainWindow *game,QObject *parent = nullptr);
    void move();
    void draw(QPainter *);
protected:
    int max_hp;//hp=health point生命值
    int current_hp;
    int sp;//sp=speed速度
    int de;//de=defence防御
    double dod;//dod=dodge rate闪避率
    int type;
    QPixmap m_figure;
    QPoint m_pos;
    MainWindow *m_game;
    QPoint entrance;
    QPoint exit;
};

#endif // GAME_ENEMY_H
