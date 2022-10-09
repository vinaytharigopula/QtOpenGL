#-------------------------------------------------
#
# Project created by QtCreator 2016-05-03T13:59:13
#
#-------------------------------------------------

QT       += core gui opengl




greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GLBegin
TEMPLATE = app
win32 {
        LIBS += -lopengl32
}

SOURCES += main.cpp\
        mainwindow.cpp \
    qglbegin.cpp

HEADERS  += mainwindow.h \
    qglbegin.h

FORMS    += mainwindow.ui
