#-------------------------------------------------
#
# Project created by QtCreator 2015-11-30T17:57:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HMPlayer_v1
TEMPLATE = app


SOURCES += main.cpp \
    mywidget.cpp \
    settings.cpp

HEADERS  += \
    mywidget.h \
    settings.h

QT       += multimedia

QT       += multimediawidgets

FORMS    +=

CONFIG += mobility
MOBILITY =

RESOURCES += \
    res.qrc

