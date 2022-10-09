#include "MyWorker.h"

MyWorker::MyWorker(QObject *parent) : QObject(parent)
{

}

void MyWorker::run(){
    QPointF Pt;
    for(int i=0;i<10000;i++){
        Pt=QPointF(rand()%1920,rand()%1000);

//        qDebug()<<Pt;
        emit sendPos(Pt);
    }
}
