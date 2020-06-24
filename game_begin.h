#ifndef GAME_BEGIN_H
#define GAME_BEGIN_H
#include<QPushButton>
#include<QtGui/QApplicationStateChangeEvent>
#include <QWidget>
#include<QPaintEvent>

#include"mainwindow.h"
namespace Ui {
class game_begin;
}

class game_begin : public QWidget
{
    Q_OBJECT

public:
    explicit game_begin(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~game_begin();
signals:
    void clicked();
private slots:
    void on_play_clicked();
    void on_quit_clicked();
    void on_hard_clicked();

private:
    Ui::game_begin *ui;
    QPushButton *play;
    QPushButton *quit;
    QPushButton *hard;
    MainWindow *m;

};

#endif // GAME_BEGIN_H
