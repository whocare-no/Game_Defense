#ifndef GAME_END_H
#define GAME_END_H
#include<QPaintEvent>
#include <QWidget>
#include<QPainter>
#include<iostream>
#include<QPushButton>
namespace Ui {
class game_end;
}

class game_end : public QWidget
{
    Q_OBJECT

public:
    explicit game_end(bool _win,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~game_end();
signals:
    void signal();
private slots:

    void on_back_clicked();

private:
    Ui::game_end *ui;
    bool win;
    QPushButton *back;
};

#endif // GAME_END_H
