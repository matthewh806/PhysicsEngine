#include <GLFW/glfw3.h>

#include "common/controls.hpp"

glm::vec3 position = glm::vec3(0, 0, 5);

float horizontalAngle = 3.0f;
float verticalAngle = 0.0f; 
float initialFoV = 45.0f;

float speed = 3.0f;
float mouseSpeed = 0.005f;

void computeMatricesFromInputs() {
    int xPos, yPos;

    // glfwGetCursorPos(&xPos, &yPos);

}

glm::mat4 getViewMatrix() {
    return glm::mat4(1.0f);
}


glm::mat4 getProjectionMatrix() {
    return glm::mat4(1.0f);
}