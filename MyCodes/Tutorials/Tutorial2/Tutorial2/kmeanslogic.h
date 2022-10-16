#ifndef KMEANSLOGIC_H
#define KMEANSLOGIC_H

#include <QObject>

#include <omp.h>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class kmeanslogic : public QObject
{
    Q_OBJECT
public:
    explicit kmeanslogic(QObject *parent = nullptr);

signals:

public :

};

#endif // KMEANSLOGIC_H
