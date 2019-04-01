#include <iostream>

#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>

#include "loadShader.hpp"

// static const struct {
//     float x, y;
//     float r,g, b;
// } vertices[3] = 
// {
//     {-0.6f, -0.4f, 1.f, 0.f, 0.f},
//     { 0.6f, -0.4f, 0.f, 1.f, 0.f},
//     {  0.f,  0.6f, 0.f, 0.f, 1.f}
// };

static const GLfloat g_vertex_buffer_data[] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
};

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(int argc, char** argv) {
    std::cout << "Hello, PhysicsEngine!" << std::endl;

    GLFWwindow* window;
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;

    if(!glfwInit()) {
        std::cout << "WELL THATS FUCKING SHIT ISNT IT MATE" << std::endl;
        return 0;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(600, 480, "PhysicsEngine", NULL, NULL);

    if(!window) {
        std::cout << "AWWW SHEEEEEEEEET" << std::endl;
        glfwTerminate();
        return 0;
    }

    glfwMakeContextCurrent(window);
    
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

    glfwSetKeyCallback(window, key_callback);
    glfwSwapInterval(1);

    GLuint programID = LoadShaders("src/shaders/simpleVertexShader.vertexshader", "src/shaders/SimpleFragmentShader.fragmentshader");

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);

    while( !glfwWindowShouldClose(window) ) {
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(programID);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            0,
            (void*)0
        );

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glDisableVertexAttribArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glDeleteBuffers(1, &vertex_buffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(programID);

    glfwTerminate();

    return 0;
}  