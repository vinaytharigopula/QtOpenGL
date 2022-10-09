#ifndef KADAPTIVEOCTREE_H
#define KADAPTIVEOCTREE_H KAdaptiveOctree

class KColor;
class KHalfEdgeMesh;
class KTransform3D;
#include <cstddef>
#include <KGeometryCloud>
#include <KSharedPointer>

class KAdaptiveOctreePrivate;
class KAdaptiveOctree : public KGeometryCloud
{
public:
  KAdaptiveOctree();
  ~KAdaptiveOctree();

  void clear();
  size_t depth() const;
  void build(BuildMethod method, TerminationPred pred);
  void debugDraw(size_t min = 0, size_t max = std::numeric_limits<size_t>::max());
  void debugDraw(KTransform3D &trans, size_t min = 0, size_t max = std::numeric_limits<size_t>::max());

private:
  KSharedPointer<KAdaptiveOctreePrivate> m_private;
};

#endif // KADAPTIVEOCTREE_H
