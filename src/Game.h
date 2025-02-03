//
// Created by Silas on 01/02/2025.
//

#ifndef GAME_H
#define GAME_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Renderer.h"
#include "InputManager.h"
#include "OrbitCamera.h"
#include "Scene.h"

class Game {
public:
    Game(int width, int height, const char* title);
    ~Game();

    void Run();  // Main game loop

private:
    void Init();    // Initialize everything
    void ProcessInput();  // Handle input
    void Update(float deltaTime);  // Update game logic
    void Render();  // Render everything

    GLFWwindow* window;
    Renderer* renderer;
    InputManager* inputManager;
    Scene* currentScene;
    OrbitCamera* camera;

    bool isRunning;
    float lastFrameTime;
};

#endif
