//
// Created by Silas on 03/02/2025.
//

#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class OrbitCamera {
public:
    OrbitCamera(float radius, float yaw, float pitch);

    void ProcessMouseMovement(float deltaX, float deltaY);
    void ProcessMouseScroll(float yOffset);
    glm::mat4 GetViewMatrix() const;

private:
    float radius;
    float yaw;   // Horizontal angle (theta)
    float pitch; // Vertical angle (phi)

    glm::vec3 position;
    glm::vec3 target;
    glm::vec3 up;

    void UpdateCameraPosition();
};

