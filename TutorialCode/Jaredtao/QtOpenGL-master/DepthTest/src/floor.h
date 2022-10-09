﻿#ifndef FLOOR_H
#define FLOOR_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
class Floor : protected QOpenGLFunctions
{
public:
    Floor();
    ~Floor();
    void Draw(QOpenGLShaderProgram *program);
protected:
    void init();
    QOpenGLBuffer arrayBuffer;
    QOpenGLTexture *texture;
};

#endif // FLOOR_H
