#ifndef GAME_POET_H
#define GAME_POET_H
#include<QObject>
#include<QPoint>
#include<QPixmap>
#include<QPainter>
#include<QLabel>
#include<QTimer>

#include<cmath>

#include"game_enemy.h"
#include"game_bullet.h"
#include<iostream>
using namespace std;
class game_poet:public QObject
{
    Q_OBJECT
public:
    explicit game_poet(QObject *parent = nullptr);
    bool existed();
    bool rangedrawed;
    void drawPoet(QPainter *);
    void drawRange(QPainter *);
    void build();
    void unbuild();
    void getType(int t);
    void getFigure();

    void chooseEnemy(game_enemy enemy[40]);
    void loseEnemy();
    void attakEnemy();
    void drawBullet(QPainter *);
    void setPos(QPoint x);
    int getExp();
    bool hastarget=false;

    double getLength(game_enemy *enemy);
    void levelup();
    int getLevel();
    void getDamage();
    void Effect(game_enemy *target);

    void getaEffect(int t1,int t2,int l1);
    void drawData(QPainter *);
    void getPro(int dif);

private slots:
    void shootWeapon();
protected:
    QString name;
    int Damage;
    int c_Damage;
    int Range;
    int Rate;
    int c_Rate;
    int exp;
    int level=1;
    int type;
    int effect;
    int Crit;
    int Effectrate;
    bool existence;
    int Pro11,Pro12,Pro13;
    QPoint pos;
    QPixmap Figure;
    QTimer *m_fireRateTimer;
    game_enemy *target;
    QList<game_bullet *>m_bullet;

};

#endif // GAME_POET_H
