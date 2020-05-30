#ifndef GAME_POETPOSITION_H
#define GAME_POETPOSITION_H
#include<QPoint>

class game_poetposition
{
public:
    game_poetposition(QPoint x);
    bool poetexitd();
    void getExistence(bool b);
    bool Pointcontained(QPoint x);

protected:
    QPoint pos;
    bool poetexistenxe;

};

#endif // GAME_POETPOSITION_H
