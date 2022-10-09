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

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected slots:
//    void resizeGL(int w, int h);
//    void paintGL();
//    void initializeGL();
protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_Start_clicked();

private:
    Ui::Widget *ui;
    QThread *mythread;
    MyWorker *worker;
};
#endif // WIDGET_H
