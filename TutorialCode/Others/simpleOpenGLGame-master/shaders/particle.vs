#version 330 core

layout( location = 0 ) in vec4 vertex;

out vec2 TexCoords;
out vec4 ParticleColor;

uniform mat4 projection;
uniform vec2 offset;
uniform vec4 color;

void main() {

    float scale = 10.0;
    ParticleColor = color;
    TexCoords = vertex.zw;
    // we scale the particle quad by 10.0f, and added an offset to the particle pos
    gl_Position = projection * vec4( ( vertex.xy * scale ) + offset, 0.0, 1.0 );

}