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

    play= new QPushButton();
    quit= new QPushButton();
    hard=new QPushButton();
    QPixmap pl;
    QPixmap qu;
    QPixmap ha;
    pl.load("../Defense_Game/Resource/play.jpg");
    qu.load("../Defense_Game/Resource/quit.png");
    ha.load("../Defense_Game/Resource/hard.png");
    ui->play->setIcon(pl);
    ui->play->setMaximumSize(60,30);
    ui->play->setMinimumSize(60,30);
    ui->play->setIconSize(QSize(60,30));
    ui->quit->setIcon(qu);
    ui->quit->setMaximumSize(60,30);
    ui->quit->setMinimumSize(60,30);
    ui->quit->setIconSize(QSize(60,30));
    ui->hard->setIcon(ha);
    ui->hard->setMaximumSize(60,30);
    ui->hard->setMinimumSize(60,30);
    ui->hard->setIconSize(QSize(60,30));

}

game_begin::~game_begin()
{
    delete ui;
}

void game_begin::on_play_clicked()
{
    this->hide();
    m=new MainWindow(1);
    m->show();
}
void game_begin::on_quit_clicked()
{
    qApp->quit();

}
void game_begin::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap begin;
    begin.load("../Defense_Game/Resource/begin.png");
    painter.drawPixmap(0,0,begin);
}

void game_begin::on_hard_clicked()
{
    this->hide();
    m=new MainWindow(2);
    m->show();
}
