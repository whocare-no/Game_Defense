#include "game_end.h"
#include "ui_game_end.h"
#include"game_begin.h"
game_end::game_end(bool win,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game_end),win(win)
{
    ui->setupUi(this);
    back=new QPushButton();
    QPixmap ba;
    ba.load("../Defense_Game/Resource/back.png");
    ui->back->setIcon(ba);
     ui->back->setIconSize(QSize(60,30));
    ui->back->show();

}
void game_end::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap end;
    if(win==true)
        end.load("../Defense_Game/Resource/win.png");
    else
        end.load("../Defense_Game/Resource/end.png");
    painter.drawPixmap(0,0,end);
}
void game_end::on_back_clicked()
{
    game_begin *begin=new game_begin();
    begin->show();
    this->close();
}

game_end::~game_end()
{
    delete ui;
}

