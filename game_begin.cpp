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
    QPixmap begin;
    play= new QPushButton();
    QPixmap pl;
    pl.load("../Defense_Game/Resource/play.jpg");
    ui->play->setIcon(pl);
    ui->play->setMaximumSize(60,30);
    ui->play->setMinimumSize(60,30);
    ui->play->setIconSize(QSize(60,30));
   // ui->play->setFixedSize(pl.size());
    begin.load("../Defense_Game/Resource/begin.png");
    ui->label->setPixmap(begin);
    ui->label->setFixedSize(begin.size());
    ui->label->show();
    QObject::connect(play,SIGNAL(clicked()),m,SLOT(on_play_clicked()));
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
