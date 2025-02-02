//
// Created by Silas on 01/02/2025.
//
// @TODO: Complete Class Missing
#include "InputManager.h"

GLFWwindow* InputManager::s_Window = nullptr;
std::unordered_map<int, bool> InputManager::s_KeyStates;
std::unordered_map<int, bool> InputManager::s_MouseStates;

void InputManager::Init(GLFWwindow* window) {
    s_Window = window;

    // GLFW Callbacks setzen
    glfwSetKeyCallback(window, KeyCallback);
    glfwSetMouseButtonCallback(window, MouseButtonCallback);
    glfwSetCursorPosCallback(window, CursorPositionCallback);
}

void InputManager::Update() {
    // Hier können zukünftige Events verarbeitet werden (z. B. Keybuffer reset)
}

bool InputManager::IsKeyPressed(int key) {
    return s_KeyStates[key];
}

bool InputManager::IsMouseButtonPressed(int button) {
    return s_MouseStates[button];
}

void InputManager::GetMousePosition(double& x, double& y) {
    glfwGetCursorPos(s_Window, &x, &y);
}

// --- Callbacks ---
void InputManager::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS)
        s_KeyStates[key] = true;
    else if (action == GLFW_RELEASE)
        s_KeyStates[key] = false;
}

void InputManager::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS)
        s_MouseStates[button] = true;
    else if (action == GLFW_RELEASE)
        s_MouseStates[button] = false;
}
void InputManager::CursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    // Falls du spezielle Cursor-Logik willst, hier einfügen
}