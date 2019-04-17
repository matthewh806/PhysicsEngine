#ifndef CONTROLS_HPP
#define CONTROLS_HPP

#include <OpenGL/gl3.h>
#include <glm/glm.hpp>

void computeMatricesFromInputs();
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();

#endif