#include "openglmesh.h"

#include <KVertex>
#include <KMacros>
#include <KHalfEdgeMesh>
#include <OpenGLBuffer>
#include <OpenGLFunctions>
#include <OpenGLVertexArrayObject>
#include <KAabbBoundingVolume>

class OpenGLMeshPrivate
{
public:
  OpenGLMeshPrivate();
  void create(const KHalfEdgeMesh &mesh);
  void vertexAttribPointer(int location, int elements, OpenGLElementType type, bool normalized, int stride, int offset);
  void vertexAttribPointer(int location, int elements, int count, OpenGLElementType type, bool normalized, int stride, int offset);
  void vertexAttribPointerDivisor(int location, int elements, OpenGLElementType type, bool normalized, int stride, int offset, int divisor);
  void vertexAttribPointerDivisor(int location, int elements, int count, OpenGLElementType type, bool normalized, int stride, int offset, int divisor);
  GLsizei m_elementCount;
  OpenGLBuffer m_indexBuffer;
  OpenGLBuffer m_vertexBuffer;
  OpenGLVertexArrayObject m_vertexArrayObject;
  KAabbBoundingVolume m_aabb;
};

OpenGLMeshPrivate::OpenGLMeshPrivate() :
  m_indexBuffer(OpenGLBuffer::IndexBuffer), m_vertexBuffer(OpenGLBuffer::VertexBuffer)
{
  // Intentionally Empty
}

void OpenGLMeshPrivate::create(const KHalfEdgeMesh &mesh)
{

  // Helpers
  m_aabb = KAabbBoundingVolume(mesh.aabb());
  KHalfEdgeMesh::FaceContainer const &faces = mesh.faces();
  KHalfEdgeMesh::VertexContainer const &vertices = mesh.vertices();
  size_t verticesSize = sizeof(KVertex) * vertices.size();
  size_t indicesCount = faces.size() * 3;
  size_t indicesSize  = sizeof(uint32_t) * indicesCount;
  OpenGLBuffer::RangeAccessFlags flags =
      OpenGLBuffer::RangeInvalidate
    | OpenGLBuffer::RangeUnsynchronized
    | OpenGLBuffer::RangeWrite;

  // Create Buffers
  m_elementCount = static_cast<GLsizei>(indicesCount);
  m_vertexArrayObject.create();
  m_vertexBuffer.create();
  m_indexBuffer.create();

  // Bind mesh
  m_vertexArrayObject.bind();
  m_vertexBuffer.bind();
  m_indexBuffer.bind();

  // Allocate Mesh
  m_vertexBuffer.allocate(verticesSize);
  m_indexBuffer.allocate(indicesSize);
  KVertex *vertDest = (KVertex*)m_vertexBuffer.mapRange(0, verticesSize, flags);
  uint32_t *indDest = (uint32_t*)m_indexBuffer.mapRange(0, indicesSize, flags);

  // Iterators
  uint32_t *baseIndDest;
  const KHalfEdgeMesh::HalfEdge *halfEdge;

  // Construct Mesh
  for (size_t i = 0; i < vertices.size(); ++i)
  {
    vertDest[i] = KVertex(vertices[i].position, vertices[i].normal);
  }
  for (size_t i = 0; i < faces.size(); ++i)
  {
    baseIndDest = &indDest[3 * i];
    halfEdge = mesh.halfEdge(faces[i].first);
    baseIndDest[0] = halfEdge->to - 1;
    halfEdge = mesh.halfEdge(halfEdge->next);
    baseIndDest[1] = halfEdge->to - 1;
    halfEdge = mesh.halfEdge(halfEdge->next);
    baseIndDest[2] = halfEdge->to - 1;
  }

  // Setup Vertex Pointers
  vertexAttribPointer(0, KVertex::PositionTupleSize, OpenGLElementType::Float, false, KVertex::stride(), KVertex::positionOffset());
  vertexAttribPointer(1, KVertex::NormalTupleSize, OpenGLElementType::Float, true, KVertex::stride(), KVertex::normalOffset());

  // Finalize Construction
  m_indexBuffer.unmap();
  m_vertexBuffer.unmap();
  m_vertexArrayObject.release();
}

void OpenGLMeshPrivate::vertexAttribPointer(int location, int elements, OpenGLElementType type, bool normalized, int stride, int offset)
{
  GL::glEnableVertexAttribArray(location);
  GL::glVertexAttribPointer(location, elements, static_cast<GLenum>(type), normalized ? GL_TRUE : GL_FALSE, stride, reinterpret_cast<const GLvoid*>(offset));
}

void OpenGLMeshPrivate::vertexAttribPointer(int location, int elements, int count, OpenGLElementType type, bool normalized, int stride, int offset)
{
  for (int i = 0; i < count; ++i)
  {
    vertexAttribPointer(location + i, elements, type, normalized, stride, static_cast<int>(offset + i * elements * OpenGLElementSize(type)));
  }
}

void OpenGLMeshPrivate::vertexAttribPointerDivisor(int location, int elements, OpenGLElementType type, bool normalized, int stride, int offset, int divisor)
{
  vertexAttribPointer(location, elements, type, normalized, stride, offset);
  GL::glVertexAttribDivisor(location, divisor);
}

void OpenGLMeshPrivate::vertexAttribPointerDivisor(int location, int elements, int count, OpenGLElementType type, bool normalized, int stride, int offset, int divisor)
{
  for (int i = 0; i < count; ++i)
  {
    vertexAttribPointerDivisor(location + i, elements, type, normalized, stride, static_cast<int>(offset + i * elements * OpenGLElementSize(type)), divisor);
  }
}

///

OpenGLMesh::OpenGLMesh() :
  m_private(new OpenGLMeshPrivate)
{
  // Intentionally Empty
}

OpenGLMesh::~OpenGLMesh()
{
  // Intentionally Empty
}

void OpenGLMesh::bind()
{
  P(OpenGLMeshPrivate);
  p.m_vertexArrayObject.bind();
}

void OpenGLMesh::setUsagePattern(OpenGLMesh::UsagePattern pattern)
{
  P(OpenGLMeshPrivate);
  p.m_indexBuffer.setUsagePattern(pattern);
  p.m_vertexBuffer.setUsagePattern(pattern);
}

void OpenGLMesh::create(const char *filename)
{
  KHalfEdgeMesh mesh;
  mesh.create(filename);
  create(mesh);
}

void OpenGLMesh::create(const KHalfEdgeMesh &mesh)
{
  P(OpenGLMeshPrivate);
  p.create(mesh);
}

void OpenGLMesh::draw()
{
  P(OpenGLMeshPrivate);
  bind();
  GL::glDrawElements(GL_TRIANGLES, p.m_elementCount, GL_UNSIGNED_INT, (const GLvoid*)0);
  release();
}

void OpenGLMesh::drawInstanced(size_t begin, size_t end)
{
  P(OpenGLMeshPrivate);

  // Some GPUs don't play nice with NOP calls to drawing instances.
  // If the call isn't going to end up drawing anythnig, simply return.
  // According to the GL standards this should be fine,
  // however I have seen this fail in practice:
  // https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glDrawElementsInstanced.xhtml
  if (begin == end)
    return;

  bind();
  if (begin == 0)
    GL::glDrawElementsInstanced(GL_TRIANGLES, p.m_elementCount, GL_UNSIGNED_INT, (const GLvoid*)0, static_cast<GLsizei>(end));
  else
    GL::glDrawElementsInstancedBaseVertex(GL_TRIANGLES, p.m_elementCount, GL_UNSIGNED_INT, (const GLvoid*)0, static_cast<int>(end - begin), static_cast<GLsizei>(begin));
  release();
}

void OpenGLMesh::vertexAttribPointer(int location, int elements, OpenGLElementType type, bool normalized, int stride, int offset)
{
  P(OpenGLMeshPrivate);
  p.vertexAttribPointer(location, elements, type, normalized, stride, offset);
}


void OpenGLMesh::vertexAttribPointer(int location, int elements, int count, OpenGLElementType type, bool normalized, int stride, int offset)
{
  P(OpenGLMeshPrivate);
  p.vertexAttribPointer(location, elements, count, type, normalized, stride, offset);
}

void OpenGLMesh::vertexAttribPointerDivisor(int location, int elements, OpenGLElementType type, bool normalized, int stride, int offset, int divisor)
{
  P(OpenGLMeshPrivate);
  p.vertexAttribPointerDivisor(location, elements, type, normalized, stride, offset, divisor);
}

void OpenGLMesh::vertexAttribPointerDivisor(int location, int elements, int count, OpenGLElementType type, bool normalized, int stride, int offset, int divisor)
{
  P(OpenGLMeshPrivate);
  p.vertexAttribPointerDivisor(location, elements, count, type, normalized, stride, offset, divisor);
}

void OpenGLMesh::release()
{
  P(OpenGLMeshPrivate);
  p.m_vertexArrayObject.release();
}

bool OpenGLMesh::isCreated() const
{
  P(const OpenGLMeshPrivate);
  return p.m_indexBuffer.isCreated() && p.m_vertexBuffer.isCreated() && p.m_vertexArrayObject.isCreated();
}

int OpenGLMesh::objectId() const
{
  P(const OpenGLMeshPrivate);
  return p.m_vertexArrayObject.objectId();
}

const KAabbBoundingVolume &OpenGLMesh::aabb() const
{
  P(const OpenGLMeshPrivate);
  return p.m_aabb;
}
