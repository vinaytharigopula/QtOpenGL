#include "Widget.h"
#include "ui_Widget.h"

#include "GLWidget.h"
#include "GlWidget2.h"



bool qcomparator(const QPair<QString, int>& a,
                 const QPair<QString, int>& b)
{
    return a.second < b.second;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->showMaximized();

    //    QString Path="G:/CAIR/maps/maps/ENC";
    //    QDir directory(Path);
    //    QStringList images = directory.entryList(QStringList() << "*.ivf" ,QDir::Files);

    //    QVector<QPair<QString, int> > Data;

    //    foreach(QString filename, images) {
    //        //do whatever you need to do
    //        QFileInfo fileinfo{Path+"/"+filename};
    //        qint64 size = fileinfo.size();

    //        QPair<QString, int> pr ;
    //        pr.first=(filename);
    //        pr.second=size;
    //        Data.append(pr);

    //        qDebug()<<filename<<size;
    //    }
    //    qDebug()<<Data;



    //     qDebug()<<" ========================================== ";


    //    connect(ui->rotXSlider, SIGNAL(valueChanged(int)), ui->openGLWidget, SLOT(setXRotation(int)));
    //    connect(ui->rotYSlider, SIGNAL(valueChanged(int)), ui->openGLWidget, SLOT(setYRotation(int)));
    //    connect(ui->rotZSlider, SIGNAL(valueChanged(int)), ui->openGLWidget, SLOT(setZRotation(int)));

    mythread=new QThread();
    worker=new MyWorker();
    worker->moveToThread(mythread);
    mythread->start();
    connect(worker, SIGNAL(sendPos(QPointF)), ui->openGLWidget, SLOT(onPosReceived(QPointF)));

    ////    QTimer::singleShot(2000,)


    connect(ui->openGLWidget, SIGNAL(sendMouseMoveEvent(QPointF)),this, SLOT(onMouseMoveEvent(QPointF)));
    connect(this, SIGNAL(sendShowAllPoints(bool)),ui->openGLWidget, SLOT(showAllPoints(bool)));
    connect(this, SIGNAL(sendClearAllPoints()),ui->openGLWidget, SLOT(clearAllPoints()));


//showAllPoint

}

void Widget::onMouseMoveEvent(QPointF P){

// ui->label_Status->setText(QString::)
}

void Widget::keyPressEvent(QKeyEvent *e){
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}

Widget::~Widget()
{
    if(mythread){
        if(mythread->isRunning()){
            mythread->disconnect();
            mythread->deleteLater();
        }
    }

    if(worker){
        worker->disconnect();
        worker->deleteLater();
    }


    delete ui;
}

void Widget::on_Start_clicked()
{
    emit sendClearAllPoints();
    if(worker){
        worker->run();
    }
}


void Widget::on_chk_ShowAllPoints_clicked(bool checked)
{
    emit sendShowAllPoints(checked);
}

