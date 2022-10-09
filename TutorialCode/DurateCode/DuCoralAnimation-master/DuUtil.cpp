#include "DuUtil.h"
#include <QtGlobal>

int DuRandom(int iL, int sL)
{
    return qrand() % sL + iL;
}
