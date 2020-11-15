#-------------------------------------------------
#
# Project created by QtCreator 2020-04-22T13:25:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2020-pd2-DoodleJump
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
    move.cpp \
    bullet.cpp \
    plates.cpp \
    general_plates.cpp \
    special_plates.cpp \
    monster.cpp \
    gerneral_monster.cpp \
    have_no_monster.cpp \
    fly_monster.cpp \
    moving_plate.cpp \
    props.cpp \
    prop_spring.cpp \
    have_no_props.cpp \
    prop_rocket.cpp \
    prop_shield.cpp

HEADERS += \
        mainwindow.h \
    move.h \
    bullet.h \
    plates.h \
    general_plates.h \
    special_plates.h \
    monster.h \
    gerneral_monster.h \
    genmonster.h \
    have_no_monster.h \
    genplates.h \
    fly_monster.h \
    moving_plate.h \
    props.h \
    prop_spring.h \
    have_no_props.h \
    genprops.h \
    prop_rocket.h \
    prop_shield.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
