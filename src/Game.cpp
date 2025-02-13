//
// Created by Silas on 01/02/2025.
//
// @TODO: Complete Class Missing
#include "Game.h"

#include <bemapiset.h>
#include <iostream>
#include <ostream>

//Constructors

Game::Game(int width, int height, const char* title) {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window); //Setting the Context for future Gl functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        exit(EXIT_FAILURE);
    }

    int fbWidth, fbHeight;
    glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
    glViewport(0, 0, fbWidth, fbHeight);

    glfwSwapInterval(1); //Enabling VSync





    //Initialize inputManager
    InputManager::GetInstance().ProcessInput(window);

    camera = new OrbitCamera(11.0f, 45.0f, 30.0f);

    // Initialize Renderer
    renderer = new Renderer(camera);

    isRunning = true;
    lastFrameTime = 0.0f;


}
//Deleter
Game::~Game() {
    delete renderer;
    delete inputManager;
    glfwDestroyWindow(window);
    glfwTerminate();
}



//Main Loop
void Game::Run() {
    Render();
    while (isRunning) {
        //Delta Time upating
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;

        ProcessInput();
        Update(deltaTime);
        Render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
void Game::ProcessInput() {
    InputManager& input = InputManager::GetInstance();
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        isRunning = false;
    }
    // Check Mouse Input
    double deltaX = input.GetMouseDeltaX();
    double deltaY = input.GetMouseDeltaY();
    camera->ProcessMouseMovement(deltaX, deltaY);
    camera->ProcessMouseScroll(input.GetScrollOffset());
    input.Update();
}
void Game::Update(float deltaTime) {
    if (currentScene) {
        currentScene->Update(deltaTime);
    }
}
void Game::Render() {
    renderer->Clear();
    if (currentScene) {

        currentScene->Render(*renderer);
    }
}
