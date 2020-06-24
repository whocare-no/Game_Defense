#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QPaintEvent>
#include<QMouseEvent>
#include<QLabel>
#include<QtGui>
#include<QTimer>
#include <QMainWindow>

#include <QMediaPlayer>
#include"game_poet.h"
#include"game_poetposition.h"
#include"game_enemy.h"
#include"game_bullet.h"
#include"game_auxiliary.h"
#include"game_end.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int t,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void timerEvent(QTimerEvent *event);
    void waveLoad();
    void drawMoney(QPainter *);
    void drawExp(QPainter *);
    void drawMissNum(QPainter *);
    void drawWaves(QPainter *);
    void poetgetPos();
    void auxEffectload();
    bool canBuy();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPoint c;
    int Money=2000;
    int Exp=0;
    int Num=0;
    int t;
    bool timstart=false;
    int m_waves=1;
    int missnum=0;
    bool flag=false;
    bool game_win=false;
    bool game_end=false;
    bool m_gameWin;

    game_poet poet[16];
    game_auxiliary aux[16];
    game_poetposition pos[16]={
        game_poetposition(QPoint(177, 76)),
        game_poetposition(QPoint(219, 74)),
        game_poetposition(QPoint(260, 73)),
        game_poetposition(QPoint(304, 74)),
        game_poetposition(QPoint(176,116)),
        game_poetposition(QPoint(219,115)),
        game_poetposition(QPoint(259,115)),
        game_poetposition(QPoint(304,114)),
        game_poetposition(QPoint(177, 192)),
        game_poetposition(QPoint(219, 192)),
        game_poetposition(QPoint(260, 192)),
        game_poetposition(QPoint(304, 192)),
        game_poetposition(QPoint(177, 232)),
        game_poetposition(QPoint(219, 232)),
        game_poetposition(QPoint(260, 232)),
        game_poetposition(QPoint(304, 232))
    };
    game_poet _c;
    game_auxiliary ac;
    QMediaPlayer *music1,*music2;
    game_enemy enemy[40];
    class game_end *end;
    int Dificulty;
    int id1,id2,id3,id4,id5;
    int t1[16],l2[16],l1[16];
};

#endif // MAINWINDOW_H
