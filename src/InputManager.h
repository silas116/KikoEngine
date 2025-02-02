//
// Created by Silas on 01/02/2025.
//
// @TODO: Complete Class Missing
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <GLFW/glfw3.h>
#include <unordered_map>

class InputManager {
public:
    static void Init(GLFWwindow* window);
    static void Update(); // 🚀 Neu: Pro Frame aktualisieren

    static bool IsKeyPressed(int key);
    static bool IsMouseButtonPressed(int button);
    static void GetMousePosition(double& x, double& y);

private:
    static GLFWwindow* s_Window;
    static std::unordered_map<int, bool> s_KeyStates;
    static std::unordered_map<int, bool> s_MouseStates;

    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
};

#endif

