#define GLEW_DLL
#define GLWF_DLL

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main() {

    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLWF3.\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    GLFWwindow* window = glfwCreateWindow(800, 600, "Triangle", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window);


    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        return -1;
    }


    while (!glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.4f, 1.0f);
        glVertex2f(-0.5f, -0.5f);
        glColor3f(1.0f, 1.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.0f, 0.4f);
        glEnd();

    
        glfwSwapBuffers(window);

  
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}

