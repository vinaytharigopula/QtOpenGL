#ifndef OPENGLRECTANGLELIGHTGROUP_H
#define OPENGLRECTANGLELIGHTGROUP_H OpenGLRectangleLightGroup

class OpenGLViewport;
class OpenGLRectangleLight;
#include <KUniquePointer>
#include <vector>
#include <cstdlib>

class OpenGLRectangleLightGroupPrivate;
class OpenGLRectangleLightGroup
{
public:
  typedef std::vector<OpenGLRectangleLight*> LightContainer;
  typedef LightContainer::size_type SizeType;
  OpenGLRectangleLightGroup();
  ~OpenGLRectangleLightGroup();

  bool create();
  void commit(const OpenGLViewport &view);
  void draw();
  OpenGLRectangleLight *createLight();

  LightContainer::iterator begin();
  LightContainer::iterator end();
  SizeType size() const;
  OpenGLRectangleLight *operator[](int idx);
private:
  KUniquePointer<OpenGLRectangleLightGroupPrivate> m_private;
};

#endif // OPENGLRECTANGLELIGHTGROUP_H
