#ifndef MYWORKER_H
#define MYWORKER_H

#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QVector>

class MyWorker : public QObject
{
    Q_OBJECT
public:
    explicit MyWorker(QObject *parent = nullptr);

public slots:
    void run();

    void initGridLogic();
signals:
    void sendPos(QPointF P);

private slots:
    void showGrid(double w = 0, double h = 0, int w_Div = 10, int h_Div = 6);
};

#endif // MYWORKER_H
