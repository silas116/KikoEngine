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



    // Initialize Renderer
    renderer = new Renderer();

    //Initialize inputManager
    inputManager = new InputManager();

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
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        isRunning = false;
    }
    inputManager->Update();
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
