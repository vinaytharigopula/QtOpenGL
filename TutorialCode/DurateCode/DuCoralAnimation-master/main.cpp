#include "Widget.h"
#include <QApplication>
#include <ctime>
//#include <QDebug>
//#include "DuUtil.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(time(nullptr));
    a.setStyle("fusion");
//    qDebug() << DuRandom(1, 5);
//    return 0;
    Widget w;
    w.show();
    return a.exec();
}
