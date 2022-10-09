#ifndef BALLOBJECT_H
#define BALLOBJECT_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "texture.h"
#include "sprite_renderer.h"
#include "game_object.h"

class BallObject : public GameObject {

public:

    // ball state
    bool Sticky, PassThrough;
    float Radius;
    bool Stuck;

    BallObject();
    BallObject( glm::vec2 pos, float radius, glm::vec2 velocity, Texture2D sprite );

    glm::vec2 Move( float dt, unsigned int window_width );
    void Reset( glm::vec2 position, glm::vec2 velocity );

};

#endif