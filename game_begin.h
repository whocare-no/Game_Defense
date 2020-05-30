#ifndef GAME_BEGIN_H
#define GAME_BEGIN_H
#include<QPushButton>
#include <QWidget>
#include"mainwindow.h"
namespace Ui {
class game_begin;
}

class game_begin : public QWidget
{
    Q_OBJECT

public:
    explicit game_begin(QWidget *parent = nullptr);
    ~game_begin();
signals:
    void clicked();
private slots:
    void on_play_clicked();

private:
    Ui::game_begin *ui;
    QPushButton *play;
    MainWindow *m;
};

#endif // GAME_BEGIN_H
