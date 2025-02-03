//
// Created by Silas on 01/02/2025.
//
// @TODO: Complete Class Missing
#include "Renderer.h"

#include <iostream>

#include "Shader.h"
#include <glad/glad.h>

Renderer::Renderer() {
    glEnable(GL_DEPTH_TEST);
    shader = new Shader("C:/Users/Silas/CLionProjects/Kiko/src/vertex_shader.glsl", "C:/Users/Silas/CLionProjects/Kiko/src/fragment_shader.glsl");

    // Define triangle vertices and indices
    std::vector<Vertex> vertices = {
        {{ 0.5f,  0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.5f, 1.0f}},
        {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
        {{-0.5f,  0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}}
    };
    std::vector<unsigned int> indices = { 0, 1, 2, 2, 3, 0 };

    // Create and store the mesh once
    mesh = new Mesh(vertices, indices);
}

Renderer::~Renderer() {
    delete shader;
    delete mesh;
}

void Renderer::Clear() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::SetClearColor(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void Renderer::DrawTriangle() {
    if (!shader) {
        std::cerr << "Shader konnte nicht geladen werden!" << std::endl;
    }
    std::vector<Vertex> vertices = {
        {{ 0.5f,  0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.5f, 1.0f}},
        {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
        {{ -0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}}
    };

    std::vector<unsigned int> indices = { 0, 1, 2, 2, 3, 0 };

    mesh = new Mesh(vertices, indices);

    shader->Use();  // Aktivieren

    // **1. Model Matrix (Identity for now)**
    glm::mat4 model = glm::mat4(1.0f);

    // **2. View Matrix (from the Camera)**
    glm::mat4 view = camera.GetViewMatrix();  // THIS IS WHAT YOU WERE MISSING!

    // **3. Projection Matrix (Perspective)**
    glm::mat4 projection = glm::perspective(glm::radians(45.0f),  // FOV
                                            800.0f / 600.0f,       // Aspect Ratio
                                            0.1f, 100.0f);         // Near and Far planes

    // **4. Pass Matrices to the Shader**
    shader->SetMat4("model", model);
    shader->SetMat4("view", view);
    shader->SetMat4("projection", projection);

    mesh->Draw();
}

