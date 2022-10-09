#include "openglspotlightgroup.h"

#include <KMath>
#include <KMatrix4x4>
#include <OpenGLMesh>
#include <OpenGLElementType>
#include <OpenGLUniformBufferObject>
#include <OpenGLRenderBlock>

bool OpenGLSpotLightGroup::create()
{
  // Create Regular Shader
  m_regularLight = new OpenGLShaderProgram();
  m_regularLight->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/resources/shaders/lighting/spotLight.vert");
  m_regularLight->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/resources/shaders/lighting/spotLight.frag");
  m_regularLight->link();

  // Create Shadowed Shader
  m_shadowCastingLight = new OpenGLShaderProgram;
  m_shadowCastingLight->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/resources/shaders/lighting/shadowSpotLight.vert");
  m_shadowCastingLight->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/resources/shaders/lighting/shadowSpotLightExponential.frag");
  m_shadowCastingLight->link();

  // Create Mapping Shader
  m_shadowMappingLight = new OpenGLShaderProgram;
  m_shadowMappingLight->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/resources/shaders/lighting/mapSpotLight.vert");
  m_shadowMappingLight->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/resources/shaders/lighting/mapSpotLightExponential.frag");
  m_shadowMappingLight->link();

  return LightGroup::create();
}

void OpenGLSpotLightGroup::initializeMesh(OpenGLMesh &mesh)
{
  mesh.vertexAttribPointerDivisor(1, 4,     OpenGLElementType::Float, false, sizeof(DataType), DataType::TranslationOffset() , 1);
  mesh.vertexAttribPointerDivisor(2, 4,     OpenGLElementType::Float, false, sizeof(DataType), DataType::DirectionOffset()   , 1);
  mesh.vertexAttribPointerDivisor(4, 4,     OpenGLElementType::Float, false, sizeof(DataType), DataType::AttenuationOffset() , 1);
  mesh.vertexAttribPointerDivisor(5, 4,     OpenGLElementType::Float, false, sizeof(DataType), DataType::DiffuseOffset()     , 1);
  mesh.vertexAttribPointerDivisor(6, 3,     OpenGLElementType::Float, false, sizeof(DataType), DataType::SpecularOffset()    , 1);
  mesh.vertexAttribPointerDivisor(7, 4, 4,  OpenGLElementType::Float, false, sizeof(DataType), DataType::PerpectiveOffset()  , 1);
}

void OpenGLSpotLightGroup::translateBuffer(const OpenGLRenderBlock &stats, DataPointer data, ConstLightIterator begin, ConstLightIterator end)
{
  // Upload data to GPU
  DataPointer lightDest;
  ConstLightPointer lightSource;
  while (begin != end)
  {
    lightDest   = data;
    lightSource = *begin;
    lightDest->m_innerAngle   = lightSource->innerAngle();
    lightDest->m_outerAngle   = lightSource->outerAngle();
    lightDest->m_diffAngle    = lightSource->outerAngle() - lightSource->innerAngle();
    lightDest->m_attenuation  = Karma::ToGlm(lightSource->attenuation());
    lightDest->m_maxFalloff   = lightSource->depth();
    lightDest->m_diffuse      = Karma::ToGlm(lightSource->diffuse());
    lightDest->m_direction    = glm::vec3(glm::normalize(stats.worldToView() * Karma::ToGlm(lightSource->direction(), 0.0f)));
    lightDest->m_perspTrans   = stats.worldToPersp() * Karma::ToGlm(lightSource->toMatrix());
    lightDest->m_specular     = Karma::ToGlm(lightSource->specular());
    lightDest->m_viewTrans    = glm::vec3(stats.worldToView() * Karma::ToGlm(lightSource->translation(), 1.0f));
    lightDest->m_minFalloff   = 0.0f;
    lightDest->m_nearPlane    = 0.1f;
    lightDest->m_exponential  = 1.0f;
    ++data;
    ++begin;
  }
}
#include <KCamera3D>
void OpenGLSpotLightGroup::translateUniforms(const OpenGLRenderBlock &stats, Byte *data, OpenGLLightGroup::SizeType step, OpenGLLightGroup::ConstLightIterator begin, OpenGLLightGroup::ConstLightIterator end)
{
  // Upload data to GPU
  DataPointer lightDest;
  KMatrix4x4 lWorldToView;
  KMatrix4x4 lViewToPersp;
  ConstLightPointer lightSource;
  while (begin != end)
  {
    lightDest   = reinterpret_cast<DataType*>(data);
    lightSource = *begin;
    if (lightSource->active())
    {
      lWorldToView = lightSource->toMatrix();
      lWorldToView.flipCoordinates();
      lViewToPersp.setToIdentity();
      lViewToPersp.perspective(2.0f * Karma::RadsToDegrees(lightSource->outerAngle()), 1.0f, 0.01f, lightSource->depth());
      lightDest->m_innerAngle   = lightSource->innerAngle();
      lightDest->m_outerAngle   = lightSource->outerAngle();
      lightDest->m_diffAngle    = lightSource->outerAngle() - lightSource->innerAngle();
      lightDest->m_attenuation  = Karma::ToGlm(lightSource->attenuation());
      lightDest->m_maxFalloff   = lightSource->depth();
      lightDest->m_diffuse      = Karma::ToGlm(lightSource->diffuse());
      lightDest->m_direction    = glm::vec3(glm::normalize(stats.worldToView() * Karma::ToGlm(lightSource->direction(), 0.0f)));
      lightDest->m_perspTrans   = stats.worldToPersp() * Karma::ToGlm(lightSource->toMatrix());
      lightDest->m_specular     = Karma::ToGlm(lightSource->specular());
      lightDest->m_viewTrans    = glm::vec3(stats.worldToView() * Karma::ToGlm(lightSource->translation(), 1.0f));
      lightDest->m_cViewToLPersp= Karma::ToGlm(lViewToPersp) * glm::inverse(Karma::ToGlm(lWorldToView)) * stats.viewToWorld();
      lightDest->m_exponential  = 1000.0f;
      lightDest->m_minFalloff   = 0.0f;
      lightDest->m_nearPlane    = 0.1f;
      data += step;
    }
    ++begin;
  }
}
