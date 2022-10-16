#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QThread>

#include <gl/GLU.h>
#include <gl/GL.h>

#include <QWidget>
#include <QTimer>
#include <QSlider>

#include "MyWorker.h"


#include <iostream>
#include <utility>

#include <QDir>
#include <QMap>
#include <QPair>

#include <QFileInfo>
#include <QtAlgorithms>
#include <algorithm>
#include <QMapIterator>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

using namespace std;


struct MySortX{
    bool operator()(qint64 &s1,qint64 &s2){
        return s1<s2;
    }
};

//struct MySort2{
//    bool operator()(QPair<QString,int> s1,QPair<QString,int> s2){

//        return s1.second ()<s2.second ();
//    }
//};

//bool cmp(const  QPair<QString,int>& a,const  QPair<QString, int>& b)
//{
//    return (a.second < b.second);
//}

// Comparator function to sort pairs
// according to second value



class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
signals:
    void sendShowAllPoints(bool B);
    void sendClearAllPoints();
protected slots:
//    void resizeGL(int w, int h);
//    void paintGL();
//    void initializeGL();
protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_Start_clicked();

    void onMouseMoveEvent(QPointF P);
    void on_chk_ShowAllPoints_clicked(bool checked);

private:
    Ui::Widget *ui;
    QThread *mythread;
    MyWorker *worker;


    MySortX srt;
};
#endif // WIDGET_H
