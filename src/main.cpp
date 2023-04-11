#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game/Tangram.h"
#include "game/Figure.h"

const GLuint WIDTH = 800;
const GLuint HEIGHT = 650;
const char* figureVertexSource = "../src/glsl/figure.vert";
const char* figureFragmentSource = "../src/glsl/figure.frag";
const char* figureTextureSource = "../resources/textures/Paper_cream_grid_blue.png";

int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Tangram3D", nullptr, nullptr);

    if(window == nullptr){
        std::cout << "Error!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0, 0, WIDTH, HEIGHT);

    Figure triangle(figureVertexSource, figureFragmentSource, figureTextureSource,EQUILATERAL_TRIANGLE_VERTICES, EQUILATERAL_TRIANGLE_INDICES);
//    Figure square(figureVertexSource, figureFragmentSource, CUBE2D_VERTICES, CUBE2D_INDICES);

    glEnable(GL_DEPTH_TEST);

    while(!glfwWindowShouldClose(window)){
        glClearColor(0.01f, 0.13f, 0.11f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        triangle.Draw(GL_TRIANGLES);
//        square.Draw(GL_TRIANGLE_FAN);

//        shaderProgram.Activate();
//        VAO1.Bind();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    triangle.Delete();
//    square.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}