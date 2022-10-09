#include "GlWidget2.h"

GlWidget2::GlWidget2(QWidget *parent) : QOpenGLWidget(parent)
{
    renderer.load((QString("://Resources/SVGFIles/world.svg")));
    pix=QPixmap::fromImage(QImage("://Resources/PlaneImages/images.png"));
    pix=pix.scaled(20,20,Qt::KeepAspectRatio);
    update();
}
void GlWidget2::initializeGL()
{
    //qglClearColor(Qt::black);
    glClearColor(1, 1, 1, 1); //sets a Green background
    //    glEnable(GL_DEPTH_TEST);
    //    glEnable(GL_CULL_FACE);
    //    glShadeModel(GL_SMOOTH);
    //    glEnable(GL_LIGHTING);
    //    glEnable(GL_LIGHT0);

    //    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    //    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void GlWidget2::onPosReceived(QPointF P){
    drawPos=P;

    qDebug()<<" set Point "<<drawPos;

    repaint();
}

void GlWidget2::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    renderer.render(&painter);
    painter.drawPixmap(drawPos,pix);
    //painter.setViewport(rect().x(), rect().y(), size.width(), size.height());

    painter.save();

    qDebug()<<drawPos;

//    for (int i=0;i<1000 ;i++ ) {
//        painter.setPen(QPen(Qt::red));
//        painter.drawPoint(QPoint(rand()%1920,rand()%1000));
//    }

    //update();
}
void GlWidget2::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void GlWidget2::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        //setXRotation(xRot + 8 * dy);
        //setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        //setXRotation(xRot + 8 * dy);
        //setZRotation(zRot + 8 * dx);
    }

    lastPos = event->pos();
}

void GlWidget2::wheelEvent(QWheelEvent *event)
{

    QPoint numDegrees = event->angleDelta();
    int cursorX = event->x();
    int cursorY = height() - event->y();

    if (numDegrees.y() < 0) zoomScale = zoomScale/1.1f; // ZOOM OUT
    if (numDegrees.y() > 0) zoomScale = zoomScale*1.1f; //ZOOM IN

    qDebug()<<" Num Of Degree "<<numDegrees<<" zoomScale "<<zoomScale;

    if( zoomScale <= 1.0f) {
        zoomScale = 1.0f;
        m_zoomTransX = 0.0f;
        m_zoomTransY = 0.0f;
    } else {
        m_zoomTransX = - cursorX + cursorX*zoomScale;
        m_zoomTransY = - cursorY + cursorY*zoomScale;
    }

    if(event->pos() != m_lastZoomPos && (numDegrees.y() > 0)) {
        m_lastZoomPos = event->pos();
    }
    resizeGL(width(),height());
    update();
}


//QSize GlWidget2::minimumSizeHint() const
//{
//    return QSize(50, 50);
//}

//QSize GlWidget2::sizeHint() const
//{
//    return QSize(400, 400);
//}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}


//void GlWidget2::initializeGL()
//{
//    //qglClearColor(Qt::black);
//    glClearColor(0, 1, 0, 1); //sets a Green background
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);
//    glShadeModel(GL_SMOOTH);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);

//    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
//    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
//}

//void GlWidget2::paintGL()
//{
////    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////    glLoadIdentity();
////    glTranslatef(0.0, 0.0, -10.0);
////    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
////    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
////    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
////    draw();
//}

//void GlWidget2::resizeGL(int width, int height)
//{
//    int side = qMin(width, height);
//    glViewport((width - side) / 2, (height - side) / 2, side, side);

//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//#ifdef QT_OPENGL_ES_1
//    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
//#else
//    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
//#endif
//    glMatrixMode(GL_MODELVIEW);
//}


//void GlWidget2::draw()
//{
//    //qglColor(Qt::red);
//    glBegin(GL_QUADS);
//        glNormal3f(0,0,-1);
//        glVertex3f(-1,-1,0);
//        glVertex3f(-1,1,0);
//        glVertex3f(1,1,0);
//        glVertex3f(1,-1,0);

//    glEnd();
//    glBegin(GL_TRIANGLES);
//        glNormal3f(0,-1,0.707);
//        glVertex3f(-1,-1,0);
//        glVertex3f(1,-1,0);
//        glVertex3f(0,0,1.2);
//    glEnd();
//    glBegin(GL_TRIANGLES);
//        glNormal3f(1,0, 0.707);
//        glVertex3f(1,-1,0);
//        glVertex3f(1,1,0);
//        glVertex3f(0,0,1.2);
//    glEnd();
//    glBegin(GL_TRIANGLES);
//        glNormal3f(0,1,0.707);
//        glVertex3f(1,1,0);
//        glVertex3f(-1,1,0);
//        glVertex3f(0,0,1.2);
//    glEnd();
//    glBegin(GL_TRIANGLES);
//        glNormal3f(-1,0,0.707);
//        glVertex3f(-1,1,0);
//        glVertex3f(-1,-1,0);
//        glVertex3f(0,0,1.2);
//    glEnd();
//}
