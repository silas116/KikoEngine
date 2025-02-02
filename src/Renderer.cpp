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
}

Renderer::~Renderer() {
    delete shader;
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
    float vertices[] = {
        0.0f,  1.0f, 0.8f,
       -0.5f, -1.0f, 0.8f,
        0.5f, -0.5f, 0.0f
    };

    if (VAO == 0) {  // Erst einmalig erzeugen

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }


    shader->Use();  // Aktivieren


    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

