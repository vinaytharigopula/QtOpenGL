#include "GlWidget2.h"

GlWidget2::GlWidget2(QWidget *parent) : QOpenGLWidget(parent)
{

    temp.clear();
    gridPoints.clear();

    zoomScale=1.0f;
    m_zoomTransX=1.0f;
    initGridLogic();


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

    int gridno=getGridNumber(drawPos);
    //qDebug()<<" Point "<<drawPos<<" grid "<<gridno<<gridPoints[gridno];

    if(gridno>=0 && gridno<gridPoints.size()){
        //        temp=gridPoints.at(gridno);
        //        temp.append(drawPos);
        //        gridPoints.replace(gridno,temp);

        gridPoints[gridno].append(drawPos);
    }



    repaint();
}

int GlWidget2::getGridNumber(QPointF p){
    int numX=p.x()/w_maingrid;
    int numY=p.y()/h_maingrid;
    int gridval=0;
    if(numY<=0){
        gridval=numX;//ok
    }else if(numX<=0){
        gridval=numY*GridSize.x();// ok
    }else{
        gridval=numX+numY*GridSize.x();
    }
    //qDebug()<<p<<"gridval"<<gridval<<numX<<numY<<"   "<<w_maingrid<<h_maingrid<<GridSize;

    return gridval;
}

void GlWidget2::paintEvent(QPaintEvent *event) {

    QPainter painter(this);
    painter.eraseRect(event->rect());


    renderer.render(&painter);
    painter.setRenderHint(QPainter::Antialiasing);



    // draw Grid
    QRect rec;
    for (int i=0;i<Vecrec.size();i++) {
        rec=Vecrec.at(i);
        painter.setPen(QPen(Qt::blue));
        painter.drawText(rec.x()+1,(rec.y()+rec.height()/10),QString::number(i+1));
        painter.setPen(QPen(Qt::green));
        painter.drawRect(rec);
    }


    // draw Ellipse
    if(showAllPoint){
        for (auto val :gridPoints ) {
            for (auto val2 :val ) {
                painter.setPen(QPen(Qt::red));
                painter.drawEllipse(val2.x()-4,val2.y()-4,8,8);
            }
        }
    }else{
        for (auto val :gridPoints.at(drawingGrid) ) {
            painter.setPen(QPen(Qt::red));
            painter.drawEllipse(val.x()-(4),val.y()-(4),8,8);
        }
    }



    //painter.setViewport(rect().x(), rect().y(), size.width(), size.height());

    // painter.save();

    //qDebug()<<drawPos;

    //    for (int i=0;i<1000 ;i++ ) {
    //        painter.setPen(QPen(Qt::red));
    //        painter.drawPoint(QPoint(rand()%1920,rand()%1000));
    //    }

    //update();
}
void GlWidget2::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();

    drawingGrid=getGridNumber(lastPos);
    repaint();
    qDebug()<<" Pressed at"<<lastPos<<" gridno"<<drawingGrid;

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



    // emit sendMouseMoveEvent(event->pos());
}

void GlWidget2::wheelEvent(QWheelEvent *event)
{

    QPoint numDegrees = event->angleDelta();
    double deltaVal = numDegrees.y() /1200.0f;
    m_zoomTransX=m_zoomTransX-deltaVal;

    if(m_zoomTransX>1.0f){
        m_zoomTransX=1.0f;
    }

    if(m_zoomTransX<0.1f){
        m_zoomTransX=0.1;
    }

    qDebug()<<" cursorY "<<deltaVal <<" zoomScale"<<zoomScale<<" zoomfactor "<<m_zoomTransX;



    resizeGL(width()*m_zoomTransX,height()*m_zoomTransX);
    update();
}



static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}


void GlWidget2::showGrid(double w,double h,int w_Div,int h_Div){
    //
    w_maingrid=w/w_Div;
    h_maingrid=h/h_Div;
    //qDebug()<<"w_maingrid "<<w_maingrid<<"h_maingrid "<<h_maingrid;


    GridSize=QPoint(w_Div,h_Div);

    QRect rec;
    rec.setWidth(w_maingrid);
    rec.setHeight(h_maingrid);
    rec.setX(1);
    rec.setY(1);

    QRect rec2;
    rec2=rec;

    //    QVector<QRect> Vecrec;
    QVector<QRect> temp;
    Vecrec.clear();



    temp.clear();
    gridPoints.clear();

    for (int i=1;i<=h ;i+=h_maingrid ) {
        GridSize.setY(GridSize.y()+1);
        temp.clear();
        for (int j=1;j<=w ;j+=w_maingrid ) {
            rec2.setX(j*rec.x());
            rec2.setY(i*rec.y());
            rec2.setWidth(w_maingrid);
            rec2.setHeight(h_maingrid);

            //qDebug()<<i<<j<<rec2<<endl;
            temp.append(rec2);
        }
        // qDebug()<<"==================================";

        Vecrec.append(temp);
    }

    gridPoints.resize(Vecrec.size());
    qDebug()<<"gridPoints size"<<gridPoints.size()<<" Vec Size"<<Vecrec.size();
}

void GlWidget2::initGridLogic(){
    double w_width=1920;
    double w_height=800;
    int w_Division=10;
    int h_Division=6;
    showGrid(w_width,w_height,w_Division,h_Division);
}

void GlWidget2::showAllPoints(bool B){
    showAllPoint=B;
    repaint();
}
void GlWidget2::clearAllPoints(){
    int size=gridPoints.size();
    gridPoints.clear();
    gridPoints.resize(size);
}
