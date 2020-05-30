#ifndef GAME_POET_H
#define GAME_POET_H
#include<QPoint>
#include<QPixmap>
#include<QPainter>
#include<QLabel>
class game_poet
{
public:
    game_poet(QPoint x);
    bool existed();
    bool poetdrawed;
    void drawPoet(QPainter *);
    void drawRange(QPainter *);
    void build();
    void unbuild();
    void getType(int t);
    void getFigure();
    //void levelup();
protected:
    int Damage;
    int Range;
    int Rate;
    int exp;
    int type;
    bool existence;

    QPoint pos;
    QPixmap Figure;
};

#endif // GAME_POET_H
