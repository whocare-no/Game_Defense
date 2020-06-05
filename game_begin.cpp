#include "game_begin.h"
#include "ui_game_begin.h"
#include"mainwindow.h"
#include<QObject>
#include<QPixmap>
game_begin::game_begin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game_begin)
{
    ui->setupUi(this);
    m= new MainWindow();
    play= new QPushButton();
    QPixmap begin;
    QPixmap pl;
    pl.load("../Defense_Game/Resource/play.jpg");
    ui->play->setIcon(pl);
    ui->play->setMaximumSize(60,30);
    ui->play->setMinimumSize(60,30);
    ui->play->setIconSize(QSize(60,30));
    begin.load("../Defense_Game/Resource/begin.png");
    ui->label->setPixmap(begin);
    ui->label->show();

}

game_begin::~game_begin()
{
    delete ui;
}

void game_begin::on_play_clicked()
{
    this->hide();
    m->show();
}
