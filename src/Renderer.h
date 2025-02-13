//
// Created by Silas on 01/02/2025.
//
// @TODO: Complete Class Missing
#ifndef RENDERER_H
#define RENDERER_H
#include "Mesh.h"
#include "OrbitCamera.h"
#include "Shader.h"


class Renderer {
public:
    Renderer(OrbitCamera*);
    ~Renderer();

    void Clear() const;                   // Bildschirm leeren
    void SetClearColor(float r, float g, float b, float a);

    void DrawTriangle();
private:
    Mesh* mesh;
    Shader* shader;
    OrbitCamera* camera;

};

#endif
