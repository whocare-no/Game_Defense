#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H
#include <QObject>
#include<QPainter>
class game_enemy : public QObject
{
    Q_OBJECT
public:
    explicit game_enemy(QObject *parent = nullptr);

    void move();
    void draw(QPainter *);
    void birth();
    void death();
    bool Live();
    void getAttacked(int atk);
    QPoint getPos()const;
    void updata();
    bool dead=false;
    int t;
    //void doActivate();
protected:
    int max_hp;//hp=health point生命值
    int current_hp;
    int sp;//sp=speed速度
    int de;//de=defence防御
    double dod;//dod=dodge rate闪避率

    int type;
    //bool m_active;
    bool enemyLive=false;
    bool enemyMiss=false;
    QPixmap m_figure;
    QPoint m_pos;
    QPoint entrance[2];
    //QPoint entrance2;
    QPoint exit;
};

#endif
