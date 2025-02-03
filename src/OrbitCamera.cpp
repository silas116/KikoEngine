//
// Created by Silas on 03/02/2025.
//

#include "OrbitCamera.h"
#include <glm/gtc/constants.hpp>

OrbitCamera::OrbitCamera(float radius, float yaw, float pitch)
    : radius(radius), yaw(yaw), pitch(pitch), target(glm::vec3(0.0f)), up(glm::vec3(0.0f, 1.0f, 0.0f)) {
    UpdateCameraPosition();
}

void OrbitCamera::UpdateCameraPosition() {
    // Convert spherical coordinates to Cartesian
    float x = radius * cos(glm::radians(pitch)) * sin(glm::radians(yaw));
    float y = radius * sin(glm::radians(pitch));
    float z = radius * cos(glm::radians(pitch)) * cos(glm::radians(yaw));

    position = glm::vec3(x, y, z) + target; // Offset from target

    // Recalculate up vector (optional for more stability)
    up = glm::normalize(glm::cross(glm::cross(glm::vec3(0,1,0), position - target), position - target));


}

void OrbitCamera::ProcessMouseMovement(float deltaX, float deltaY) {
    yaw += deltaX * 0.1f;   // Sensitivity
    pitch -= deltaY * 0.1f; // Invert Y

    // Limit pitch to prevent flipping
    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    UpdateCameraPosition();
}

void OrbitCamera::ProcessMouseScroll(float yOffset) {
    radius -= yOffset * 0.5f; // Zoom sensitivity
    if (radius < 2.0f) radius = 2.0f;  // Min zoom
    if (radius > 50.0f) radius = 50.0f; // Max zoom

    UpdateCameraPosition();
}

glm::mat4 OrbitCamera::GetViewMatrix() const {
    return glm::lookAt(position, target, up);
}

