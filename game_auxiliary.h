#ifndef AUXILIARY_H
#define AUXILIARY_H

#include<QPainter>
#include<QPoint>
#include"game_poet.h"
class game_auxiliary:public game_poet
{
public:
    game_auxiliary();

    void drawData(QPainter *);
    int Type()const;

protected:
    QPoint m_pos;

    QPixmap m_figure;

};

#endif // AUXILIARY_H
