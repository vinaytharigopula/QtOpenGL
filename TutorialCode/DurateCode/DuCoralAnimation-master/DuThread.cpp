#include "DuThread.h"

DuThread::DuThread(int miliseconds, QObject *parent)
    : QThread(parent)
{
    mMiliseconds = miliseconds;
}

void DuThread::run()
{
    while (true) {
        QThread::msleep(mMiliseconds);
        emit timeOut();
    }
}

