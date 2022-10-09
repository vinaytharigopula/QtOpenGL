/*******************************************************************************
 * debug/world.vert
 *------------------------------------------------------------------------------
 * Moves the current point to screen position.
 ******************************************************************************/

#include <GlobalBuffer.ubo>

layout(location = 0) in highp vec3 position;
layout(location = 1) in highp vec3 color;
out highp vec4 vColor;

void main()
{
  gl_Position = Current.WorldToPersp * vec4(position, 1.0);
  vColor = vec4(color, 1.0);
}
