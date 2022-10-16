#include "MyWorker.h"

MyWorker::MyWorker(QObject *parent) : QObject(parent)
{
    //initGridLogic();

}

void MyWorker::run(){
    qDebug()<<"run";
    QPointF Pt;
    for(int i=0;i<10000;i++){
        Pt=QPointF((rand()%1800)+10,(rand()%900)+10);

        //qDebug()<<i<<Pt;
        emit sendPos(Pt);
    }
}


void MyWorker::initGridLogic(){
    double w_width=1800;
    double w_height=900;

    int w_Division=10;
    int h_Division=6;



    showGrid(w_width,w_height,w_Division,h_Division);




}

void MyWorker::showGrid(double w,double h,int w_Div,int h_Div){
    //
    int w_maingrid=w/w_Div;
    int h_maingrid=h/h_Div;
    qDebug()<<"w_maingrid "<<w_maingrid<<"h_maingrid "<<h_maingrid;

    QRect rec;
    rec.setWidth(w);
    rec.setHeight(h);
    rec.setX(1);
    rec.setY(1);

    QRect rec2;
    rec2=rec;

    QVector<QRect> Vecrec;

    QVector<QRect> temp;

    Vecrec.clear();
    for (int i=1;i<=h ;i+=h_maingrid ) {

        temp.clear();
        for (int j=1;j<=w ;j+=w_maingrid ) {
            rec2.setX(j*rec.x());
            rec2.setY(i*rec.y());

            temp.append(rec2);
        }

        qDebug()<<i<<temp;
        Vecrec.append(temp);



        //        rec2.setX(i*rec.x());
        //        rec2.setY(rec.y());

        //        Vecrec.append(rec2);
    }

    qDebug()<<Vecrec;


}
