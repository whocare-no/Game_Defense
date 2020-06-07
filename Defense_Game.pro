#-------------------------------------------------
#
# Project created by QtCreator 2020-05-25T19:05:45
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Defense_Game
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    game_begin.cpp \
    game_poet.cpp \
    game_poetposition.cpp \
    game_enemy.cpp \
    game_bullet.cpp


HEADERS += \
        mainwindow.h \
    game_begin.h \
    game_poet.h \
    game_poetposition.h \
    game_enemy.h \
    game_bullet.h


FORMS += \
        mainwindow.ui \
    game_begin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

