#include "game_poetposition.h"
#include<QPoint>
game_poetposition::game_poetposition(QPoint _x):pos(_x)
{
    poetexistenxe=false;
}
bool game_poetposition::Pointcontained(QPoint x)
{

    if(abs(x.x()-pos.x())<5&&abs(x.y()-pos.y())<5)
      return true;
    else
      return false;

}
bool game_poetposition::poetexitd()
{
    return poetexistenxe;
}
void game_poetposition::getExistence(bool b)
{
    poetexistenxe=b;
}
QPoint game_poetposition::getPos()
{
    return pos;
}
