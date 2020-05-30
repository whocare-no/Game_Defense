#include "mainwindow.h"
#include <QApplication>
#include"game_begin.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game_begin w;
    w.show();

    return a.exec();
}

