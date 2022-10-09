#ifndef KVECTOR3D_H
#define KVECTOR3D_H KVector3D

#include <QVector3D>

class KVector3D : public QVector3D
{
public:
  Q_DECL_CONSTEXPR KVector3D() : QVector3D() {}
  Q_DECL_CONSTEXPR KVector3D(QVector3D const& rhs) : QVector3D(rhs) {}
  explicit Q_DECL_CONSTEXPR KVector3D(float k) : QVector3D(k, k, k) {}
  Q_DECL_CONSTEXPR KVector3D(float xpos, float ypos, float zpos) : QVector3D(xpos, ypos, zpos) {}
  KVector3D operator/(KVector3D const &rhs)
  {
    return KVector3D(x() / rhs.x(), y() / rhs.y(), z() / rhs.z());
  }
};

#endif // KVECTOR3D_H

