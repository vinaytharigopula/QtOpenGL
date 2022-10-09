#ifndef GLWIDGET2_H
#define GLWIDGET2_H

#include <QOpenGLWidget>
#include <QObject>
#include <QWidget>

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QObject>
#include <iostream>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QExposeEvent>
#include <QEvent>
#include <QDebug>

#include <QApplication>
#include <QSvgRenderer>
#include <QPainter>
#include <QImage>
#include <QPainter>
#include <QWheelEvent>
#include <QBasicTimer>
#include <QImage>
#include <QPixmap>
#include <QPoint>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QHoverEvent>
#include <QWheelEvent>




using namespace std;

extern "C"{
#include <gl/GLU.h>
#include <gl/GL.h>

//#ifdef _WIN32
#include <windows.h>
//#endif

}


class GlWidget2 : public QOpenGLWidget
{
    Q_OBJECT
public:

    explicit GlWidget2(QWidget *parent = nullptr);

public slots:

    void onPosReceived(QPointF P);

protected:
    void initializeGL() override;
    //    void paintGL();
    void paintEvent(QPaintEvent *event) override;



    //    void resizeGL(int width, int height);

    //    QSize minimumSizeHint() const;
    //    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;


    void wheelEvent(QWheelEvent *event) override;

private:

    QSvgRenderer renderer;
    QPixmap pix;

    QPointF drawPos;
    QPoint lastPos;
    double zoomScale=0.0;
    double m_zoomTransX=0.0;
    double m_zoomTransY=0.0;
    QPointF m_lastZoomPos=QPointF(0,0);

};

#endif // GLWIDGET2_H
