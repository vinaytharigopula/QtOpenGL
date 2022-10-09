#ifndef QGLBEGIN_H
#define QGLBEGIN_H

// www.amin-ahmadi.com

#include <QtWidgets>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>


class QGLBegin : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit QGLBegin(QWidget *parent = 0);

    void setRotation(float x, float y, float z);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
protected:
    //void paintEvent(QPaintEvent *event) override;


signals:

public slots:

private:
    float xrot,yrot,zrot;

};

#endif // QGLBEGIN_H
