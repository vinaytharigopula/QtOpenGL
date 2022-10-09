#ifndef GLWIDGET_H
#define GLWIDGET_H


#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QObject>
#include <iostream>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>



using namespace std;

extern "C"{
#include <gl/GLU.h>
#include <gl/GL.h>

//#ifdef _WIN32
#include <windows.h>
//#endif

}

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = nullptr);
signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    // slots for xyz-rotation slider
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);



private:
    void draw();

    int xRot;
    int yRot;
    int zRot;

    QPoint lastPos;


};

#endif // GLWIDGET_H
