#include "Widget.h"
#include "ui_Widget.h"

#include "GLWidget.h"
#include "GlWidget2.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->showMaximized();



    //    connect(ui->rotXSlider, SIGNAL(valueChanged(int)), ui->openGLWidget, SLOT(setXRotation(int)));
    //    connect(ui->rotYSlider, SIGNAL(valueChanged(int)), ui->openGLWidget, SLOT(setYRotation(int)));
    //    connect(ui->rotZSlider, SIGNAL(valueChanged(int)), ui->openGLWidget, SLOT(setZRotation(int)));

    mythread=new QThread();
    worker=new MyWorker();
    worker->moveToThread(mythread);
    mythread->start();
    connect(worker, SIGNAL(sendPos(QPointF)), ui->openGLWidget, SLOT(onPosReceived(QPointF)));

//    QTimer::singleShot(2000,)

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
    if(worker){
        worker->run();
    }
}

