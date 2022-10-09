#-------------------------------------------------
#
# Project created by QtCreator 2015-05-14T15:00:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DuCoralAnimation
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    DuCoralScene.cpp \
    DuCoralCharacter.cpp \
    DuThread.cpp \
    DuUtil.cpp

HEADERS  += Widget.h \
    DuCoralScene.h \
    DuCoralCharacter.h \
    DuThread.h \
    DuDefines.h \
    DuUtil.h

FORMS    += Widget.ui

QMAKE_CXXFLAGS += -std=gnu++14

RESOURCES += \
    images.qrc
