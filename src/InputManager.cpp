#include "InputManager.h"
#include <iostream>

InputManager::InputManager() : lastMouseX(0), lastMouseY(0), deltaX(0), deltaY(0), scrollOffset(0) {}

InputManager& InputManager::GetInstance() {
    static InputManager instance;
    return instance;
}

void InputManager::ProcessInput(GLFWwindow* window) {
    glfwSetKeyCallback(window, KeyCallback);
    glfwSetMouseButtonCallback(window, MouseButtonCallback);
    glfwSetCursorPosCallback(window, MouseMoveCallback);
    glfwSetScrollCallback(window, ScrollCallback);
}

void InputManager::Update() {
    deltaX = 0.0;
    deltaY = 0.0;
    scrollOffset = 0.0;
}

// 🔹 Check if a key is pressed
bool InputManager::IsKeyPressed(int key) {
    return keyStates[key];
}

// 🔹 Check if a mouse button is pressed
bool InputManager::IsMouseButtonPressed(int button) {
    return mouseButtonStates[button];
}

// 🔹 Get Mouse Movement
double InputManager::GetMouseDeltaX() const { return deltaX; }
double InputManager::GetMouseDeltaY() const { return deltaY; }

// 🔹 Get Scroll Offset
double InputManager::GetScrollOffset() const { return scrollOffset; }

// 🔹 Key Press Callback
void InputManager::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        GetInstance().keyStates[key] = true;
    } else if (action == GLFW_RELEASE) {
        GetInstance().keyStates[key] = false;
    }
}

// 🔹 Mouse Button Callback
void InputManager::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        GetInstance().mouseButtonStates[button] = true;
    } else if (action == GLFW_RELEASE) {
        GetInstance().mouseButtonStates[button] = false;
    }
}

// 🔹 Mouse Movement Callback
void InputManager::MouseMoveCallback(GLFWwindow* window, double xpos, double ypos) {
    auto& instance = GetInstance();
    if (instance.firstMouse) {
        instance.lastMouseX = xpos;
        instance.lastMouseY = ypos;
        instance.firstMouse = false;
    }

    instance.deltaX = xpos - instance.lastMouseX;
    instance.deltaY = instance.lastMouseY - ypos; // Inverted Y-axis
    instance.lastMouseX = xpos;
    instance.lastMouseY = ypos;
}

// 🔹 Scroll Callback
void InputManager::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    GetInstance().scrollOffset = yoffset;
}
