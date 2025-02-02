//
// Created by Silas on 01/02/2025.
//
// @TODO: Complete Class Missing
#include "Scene.h"
#include <iostream>

Scene::Scene() {
    // Szene initialisieren (später: Objekte laden)
    std::cout << "Scene initialized!" << std::endl;
}
Scene::~Scene() {
    std::cout << "Scene destroyed!" << std::endl;
}
void Scene::Update(float deltaTime) {
    //  Hier könnte Physik, Kollisionen etc. verarbeitet werden
    if (InputManager::IsKeyPressed(GLFW_KEY_W)) {
        std::cout << "W key pressed!" << std::endl;
    }
}
void Scene::Render(Renderer& renderer) {
    renderer.Clear();
    renderer.DrawTriangle(); //  Später: Alle GameObjects rendern

}