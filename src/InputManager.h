#pragma once
#include <GLFW/glfw3.h>
#include <unordered_map>

class InputManager {
public:
    static InputManager& GetInstance(); // Singleton pattern

    void ProcessInput(GLFWwindow* window);
    void Update();

    bool IsKeyPressed(int key);
    bool IsMouseButtonPressed(int button);

    double GetMouseDeltaX() const;
    double GetMouseDeltaY() const;
    double GetScrollOffset() const;

private:
    InputManager();

    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void MouseMoveCallback(GLFWwindow* window, double xpos, double ypos);
    static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

    std::unordered_map<int, bool> keyStates;
    std::unordered_map<int, bool> mouseButtonStates;

    double lastMouseX, lastMouseY;
    double deltaX, deltaY;
    double scrollOffset;

    bool firstMouse = true;
};
