#ifndef MYWORKER_H
#define MYWORKER_H

#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QImage>
#include <QPixmap>

class MyWorker : public QObject
{
    Q_OBJECT
public:
    explicit MyWorker(QObject *parent = nullptr);

public slots:
    void run();

signals:
    void sendPos(QPointF P);

};

#endif // MYWORKER_H
