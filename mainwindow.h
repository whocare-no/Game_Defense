#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QPaintEvent>
#include<QMouseEvent>
#include<QLabel>
#include<QtGui>
#include<time.h>
#include <QMainWindow>
#include"game_poet.h"
#include"game_poetposition.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPoint c;
    int t;
    int j=0;
    bool flag=false;
    game_poet poet[16]={
        game_poet(QPoint(177, 76)),
        game_poet(QPoint(219, 74)),
        game_poet(QPoint(260, 73)),
        game_poet(QPoint(304, 74)),
        game_poet(QPoint(176,116)),
        game_poet(QPoint(219,115)),
        game_poet(QPoint(259,115)),
        game_poet(QPoint(304,114)),
        game_poet(QPoint(177, 192)),
        game_poet(QPoint(219, 192)),
        game_poet(QPoint(260, 192)),
        game_poet(QPoint(304, 192)),
        game_poet(QPoint(177, 232)),
        game_poet(QPoint(219, 232)),
        game_poet(QPoint(260, 232)),
        game_poet(QPoint(304, 232))
    };
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
    game_poet _c=game_poet(QPoint(101,318));
    //game_poetposition pos;
};

#endif // MAINWINDOW_H
