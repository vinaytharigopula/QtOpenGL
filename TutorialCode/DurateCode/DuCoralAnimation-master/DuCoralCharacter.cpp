#include "DuCoralCharacter.h"
#include <QPainter>

DuCoralCharacter::DuCoralCharacter(const QPixmap &pixmap,
                                   int x, int y, int vx, int vy,
                                   QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    mPixmap = pixmap;
    mX = x;
    mY = y;
    mVx = vx;
    mVy = vy;
}

int DuCoralCharacter::get_w() const
{
    return mPixmap.width();
}

int DuCoralCharacter::get_h() const
{
    return mPixmap.height();
}

QRectF DuCoralCharacter::boundingRect() const
{
    return mPixmap.rect();
}

void DuCoralCharacter::paint(QPainter *painter,
                             const QStyleOptionGraphicsItem *option,
                             QWidget *widget)
{
    painter->drawPixmap(mX, mY, mPixmap);
    (void) option;
    (void) widget;
}

