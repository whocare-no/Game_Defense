#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H
#include <QObject>
#include<QPainter>
#include<QTimerEvent>
#include<iostream>
using namespace std;
class game_enemy : public QObject
{
    Q_OBJECT
public:
    explicit game_enemy(QObject *parent = nullptr);
    //game_enemy(game_enemy &_enemy);
    void move();
    void draw(QPainter *);
    void birth();
    void death();
    bool Live();
    void getAttacked(int atk);
    QPoint getPos()const;
    int getLength(QPoint pos)const ;
    void updata();
    bool dead=false;
    int t;
    void getWaves(int m_wave);
    void changeFigure(QString a);
    void changeSp();
    void changede();
    void Effect();
    void Effect(game_enemy enemy[40]);
    void drawEffect(QPainter *);
    bool INViNCIBILITY=false;//是否处于无敌状态
    void timerEvent(QTimerEvent *event);
    bool enemyMiss=false;
protected:
    int max_hp;//hp=health point生命值
    int current_hp;//当前生命值
    int sp;//sp=speed速度
    int dod;//dod=dodge rate闪避率

    int type;
    int wave;
    bool effectflag=false;
    bool effect=true;
    bool enemyLive=false;

    QPixmap m_figure;
    QPoint m_pos;
    QPoint entrance[2];


    QPoint exit;
    int id1;
};

#endif
