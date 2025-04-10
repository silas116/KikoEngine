//
// Created by Silas on 01/02/2025.
//
// @TODO: Complete Class Missing
#include "Renderer.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>

#include "Shader.h"
#include <glad/glad.h>
#include <glm/gtx/string_cast.hpp>
#include "OrbitCamera.h"

extern OrbitCamera camera;

Renderer::Renderer(OrbitCamera* cam) {
    glEnable(GL_DEPTH_TEST);
    shader = new Shader("C:/Users/Silas/CLionProjects/Kiko/src/vertex_shader.glsl", "C:/Users/Silas/CLionProjects/Kiko/src/fragment_shader.glsl");
    texture = new Texture("C:/Users/Silas/CLionProjects/Kiko/assets/Textures/img_1.png");
    camera = cam;
    // Define triangle vertices and indices
    std::vector<Vertex> vertices = {
        // Base square
        {{-3.0f, 0.0f, -3.0f}, {0.0f, -1.0f, 0.0f}, {0.0f, 0.0f}},
        {{ 3.0f, 0.0f, -3.0f}, {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f}},
        {{ 3.0f, 0.0f,  3.0f}, {0.0f, -1.0f, 0.0f}, {1.0f, 1.0f}},
        {{-3.0f, 0.0f,  3.0f}, {0.0f, -1.0f, 0.0f}, {0.0f, 1.0f}},


    };

    std::vector<unsigned int> indices = {
        // Base (two triangles)
        0, 1, 2,
        0, 2, 3,


    };

    // Create and store the mesh
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
        return;
    }

    shader->Use();  // Activate the shader
    shader->SetUniform("texture1", 0);  // Make sure the shader knows we're using texture unit 0


    // 1. Model Matrix (Identity for now)
    glm::mat4 model = glm::mat4(1.0f);

    // 2. View Matrix (from the Camera)
    glm::mat4 view = camera->GetViewMatrix();

    // 3. Projection Matrix (Perspective)
    glm::mat4 projection = glm::perspective(glm::radians(45.0f),  // FOV
                                            800.0f / 600.0f,       // Aspect Ratio
                                            0.1f, 100.0f);         // Near and Far planes

    // 4. Pass Matrices to the Shader
    shader->SetMat4("model", model);
    shader->SetMat4("view", view);
    shader->SetMat4("projection", projection);

    // **5. Bind the Texture**
    glActiveTexture(GL_TEXTURE0);
    texture->Bind();  // Assuming you have a Texture class

    // 6. Draw the Mesh
    mesh->Draw();

    // **7. Unbind the Texture (Optional)**
    texture->Unbind();
}

