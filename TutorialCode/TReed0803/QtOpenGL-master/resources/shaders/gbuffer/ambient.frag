#include <GBuffer.ubo>
out highp vec4 fColor;

void main()
{
  fColor = backbuffer();
}
