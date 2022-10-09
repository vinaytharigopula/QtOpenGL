#include "openglframebufferobject.h"

#include <QtOpenGL/QGL>
#include <KStack>
#include <OpenGLFunctions>
#include <OpenGLTexture>
#include <OpenGLRenderbufferObject>

static unsigned sg_release = 0;
static unsigned sg_currentFbo = 0;
static KStack<unsigned> sg_stack;

class OpenGLFramebufferObjectPrivate
{
public:
  OpenGLFramebufferObjectPrivate();
  int m_references;
  GLuint m_objectId;
  OpenGLFunctions m_functions;
};

OpenGLFramebufferObjectPrivate::OpenGLFramebufferObjectPrivate() :
  m_references(1), m_objectId(0)
{
  m_functions.initializeOpenGLFunctions();
  m_functions.glGenFramebuffers(1, &m_objectId);
}

///


OpenGLFramebufferObject::OpenGLFramebufferObject() :
  m_private(0)
{
  // Intentionally Empty
}

OpenGLFramebufferObject::~OpenGLFramebufferObject()
{
  removeReference();
}

void OpenGLFramebufferObject::create()
{
  removeReference();
  m_private = new OpenGLFramebufferObjectPrivate;
}

void OpenGLFramebufferObject::bind()
{
  P(OpenGLFramebufferObjectPrivate);
  sg_currentFbo = p.m_objectId;
  p.m_functions.glBindFramebuffer(GL_FRAMEBUFFER, p.m_objectId);
}

void OpenGLFramebufferObject::release()
{
  sg_currentFbo = sg_release;
  GL::glBindFramebuffer(GL_FRAMEBUFFER, sg_release);
}

void OpenGLFramebufferObject::attachTexture2D(OpenGLFramebufferObject::Target target, OpenGLFramebufferObject::Attachment attachment, OpenGLTexture &texture, int level)
{
  P(OpenGLFramebufferObjectPrivate);
  p.m_functions.glFramebufferTexture2D(target, attachment, texture.target(), texture.textureId(), level);
}

void OpenGLFramebufferObject::attachRenderbuffer(OpenGLFramebufferObject::Target target, OpenGLFramebufferObject::Attachment attachment, OpenGLRenderbufferObject &rBuffer)
{
  P(OpenGLFramebufferObjectPrivate);
  p.m_functions.glFramebufferRenderbuffer(target, attachment, GL_RENDERBUFFER, rBuffer.objectId());
}

OpenGLFramebufferObject::Status OpenGLFramebufferObject::status() const
{
  P(OpenGLFramebufferObjectPrivate);
  return static_cast<Status>(p.m_functions.glCheckFramebufferStatus(GL_FRAMEBUFFER));
}

bool OpenGLFramebufferObject::validate() const
{
  switch(status())
  {
  case OpenGLFramebufferObject::Complete:
    return true;
  case OpenGLFramebufferObject::IncompleteAttachment:
    qFatal("OpenGLFramebufferObject: Incomplete Attachment");
    return false;
  case OpenGLFramebufferObject::IncompleteMissingAttachment:
    qFatal("OpenGLFramebufferObject: Incomplete Missing Attachment");
    return false;
  case OpenGLFramebufferObject::IncompleteDrawBuffer:
    qFatal("OpenGLFramebufferObject: Incomplete Draw Buffer");
    return false;
  case OpenGLFramebufferObject::IncompleteReadBuffer:
    qFatal("OpenGLFramebufferObject: Incomplete Read Buffer");
    return false;
  case OpenGLFramebufferObject::Unsupported:
    qFatal("OpenGLFramebufferObject: Unsupported");
    return false;
  }
  qFatal("OpenGLFramebufferObject: Impossible condition!");
  return false;
}

int OpenGLFramebufferObject::objectId()
{
  P(OpenGLFramebufferObjectPrivate);
  return p.m_objectId;
}

void OpenGLFramebufferObject::drawBuffers(Attachment a1)
{
  P(OpenGLFramebufferObjectPrivate);
  GLenum buffers[] = { a1 };
  p.m_functions.glDrawBuffers(1, buffers);
}

void OpenGLFramebufferObject::drawBuffers(Attachment a1, Attachment a2)
{
  P(OpenGLFramebufferObjectPrivate);
  GLenum buffers[] = { a1, a2 };
  p.m_functions.glDrawBuffers(2, buffers);
}

void OpenGLFramebufferObject::drawBuffers(Attachment a1, Attachment a2, Attachment a3)
{
  P(OpenGLFramebufferObjectPrivate);
  GLenum buffers[] = { a1, a2, a3 };
  p.m_functions.glDrawBuffers(3, buffers);
}

void OpenGLFramebufferObject::drawBuffers(Attachment a1, Attachment a2, Attachment a3, Attachment a4)
{
  P(OpenGLFramebufferObjectPrivate);
  GLenum buffers[] = { a1, a2, a3, a4 };
  p.m_functions.glDrawBuffers(4, buffers);
}


void OpenGLFramebufferObject::drawBuffers(Attachment a1, Attachment a2, Attachment a3, Attachment a4, Attachment a5)
{
  P(OpenGLFramebufferObjectPrivate);
  GLenum buffers[] = { a1, a2, a3, a4, a5 };
  p.m_functions.glDrawBuffers(5, buffers);
}

void OpenGLFramebufferObject::pop()
{
  OpenGLFramebufferObject::bind(sg_stack.pop());
}

void OpenGLFramebufferObject::bind(unsigned id)
{
  sg_currentFbo = id;
  GL::glBindFramebuffer(GL_FRAMEBUFFER, id);
}

void OpenGLFramebufferObject::push()
{
  sg_stack.push(sg_currentFbo);
}

void OpenGLFramebufferObject::setRelease(unsigned fbo)
{
  sg_release = fbo;
}

void OpenGLFramebufferObject::removeReference()
{
  if (m_private)
  {
    P(OpenGLFramebufferObjectPrivate);
    --p.m_references;
    if (p.m_references == 0)
    {
      delete m_private;
      m_private = 0;
    }
  }
}
