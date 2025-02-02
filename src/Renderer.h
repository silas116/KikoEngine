//
// Created by Silas on 01/02/2025.
//
// @TODO: Complete Class Missing
#ifndef RENDERER_H
#define RENDERER_H
#include "Shader.h"


class Renderer {
public:
    Renderer();
    ~Renderer();
    Shader* shader;
    void Clear() const;                   // Bildschirm leeren
    void SetClearColor(float r, float g, float b, float a);

    void DrawTriangle();
private:
    unsigned int VAO = 0, VBO = 0;

};

#endif
