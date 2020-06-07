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
class game_poet:public QObject
{
    Q_OBJECT
public:
    explicit game_poet(QObject *parent = nullptr);
    bool existed();
    bool poetdrawed;
    void drawPoet(QPainter *);
    void drawRange(QPainter *);
    void build();
    void unbuild();
    void getType(int t);
    void getFigure();

    void chooseEnemy(game_enemy enemy[20]);
    void loseEnemy();
    void attakEnemy();
    void drawBullet(QPainter *);
    void setPos(QPoint x);
    int getExp();
    bool hastarget=false;

    double getLength(game_enemy *enemy);
    //void levelup();
private slots:
    void shootWeapon();
protected:
    int Damage;
    int Range;
    int Rate;
    int exp;
    int type;
    bool existence;

    QPoint pos;
    QPixmap Figure;
    QTimer *m_fireRateTimer;
    game_enemy *target;
    QList<game_bullet *>m_bullet;

};

#endif // GAME_POET_H
