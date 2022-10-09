#pragma once
#include "GLHeaders.h"

class Cube
{
public:
    Cube(GLFuncName *func);
    ~Cube();
    void draw(QOpenGLShaderProgram &program, const QMatrix4x4 &model, const QMatrix4x4 &view, const QMatrix4x4 &project);
private:
    void initBuffer();
    void initShader();
    void initTexture();
private:
    GLFuncName *m_func;
    QOpenGLBuffer m_arrayBuf;
    QOpenGLBuffer m_indexBuf;
    QOpenGLShader m_vertexShader;
    QOpenGLShader m_fragmentShader;
    QOpenGLTexture m_texture;
    quint32 m_vao;
    int m_indexCount = 0;
};

