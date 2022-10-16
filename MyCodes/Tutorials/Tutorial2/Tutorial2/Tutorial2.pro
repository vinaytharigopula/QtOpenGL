QT       += core gui opengl svg xml sql concurrent network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32 {
LIBS += -lopengl32 -lglu32 -luser32
LIBS += -lgdi32  -lkernel32  -lshell32
}

SOURCES += \
    GLWidget.cpp \
    GlWidget2.cpp \
    MyWorker.cpp \
    kmeanslogic.cpp \
    main.cpp \
    Widget.cpp

HEADERS += \
    GLWidget.h \
    GlWidget2.h \
    MyWorker.h \
    Widget.h \
    kmeanslogic.h

FORMS += \
    Widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    MyResource.qrc
