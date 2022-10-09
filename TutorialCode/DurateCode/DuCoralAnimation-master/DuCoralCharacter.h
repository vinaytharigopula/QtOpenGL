#ifndef DUCORALCHARACTER_H
#define DUCORALCHARACTER_H

#include <QGraphicsItem>
#include <QPixmap>

class DuCoralCharacter : public QGraphicsItem
{
public:
    DuCoralCharacter(const QPixmap &pixmap, int x, int y, int vx, int vy,
                     QGraphicsItem *parent = nullptr);

    void set_x(int x)
    {
        mX = x;
    }

    void set_y(int y)
    {
        mY = y;
    }

    void set_vx(int vx)
    {
        mVx = vx;
    }

    void set_vy(int vy)
    {
        mVy = vy;
    }

    int get_x() const
    {
        return mX;
    }

    int get_y() const
    {
        return mY;
    }

    int get_vx() const
    {
        return mVx;
    }

    int get_vy() const
    {
        return mVy;
    }

    int get_w() const;
    int get_h() const;
protected:
    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
private:
    QPixmap mPixmap; // imagen
    int mX;  // posición en x
    int mY;  // posición en y
    int mVx; // velocidad en x
    int mVy; // velocidad en y
};

#endif // DUCORALCHARACTER_H
