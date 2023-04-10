#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game/Tangram.h"
#include "game/Figure.h"

const GLuint WIDTH = 800;
const GLuint HEIGHT = 650;
const char* figureVertexSource = "../src/glsl/figure.vert";
const char* figureFragmentSource = "../src/glsl/figure.frag";

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


//    Shader shaderProgram(figureVertexSource, figureFragmentSource);
//
//
//
//    // Generates Vertex Array Object and binds it
//    VAO VAO1;
//    VAO1.Bind();
//
//    // Generates Vertex Buffer Object and links it to vertices
//    VBO VBO1(CUBE2D_VERTICES);
//    // Generates Element Buffer Object and links it to indices
//    EBO EBO1(CUBE2D_INDICES);
//
//    // Links VBO attributes such as coordinates and colors to VAO
//    VAO1.LinkAttribute(VBO1, 0, 3, GL_FLOAT, 6 *sizeof(float), (void*)0);
//    VAO1.LinkAttribute(VBO1, 1, 3, GL_FLOAT, 6 *sizeof(float), (void*)(3 * sizeof(float)));
//    // Unbind all to prevent accidentally modifying them
//    VAO1.Unbind();
//    VBO1.Unbind();
//    EBO1.Unbind();

    Figure triangle(figureVertexSource, figureFragmentSource, EQUILATERAL_TRIANGLE_VERTICES, EQUILATERAL_TRIANGLE_INDICES);
    Figure square(figureVertexSource, figureFragmentSource, CUBE2D_VERTICES, CUBE2D_INDICES);

    glEnable(GL_DEPTH_TEST);

    while(!glfwWindowShouldClose(window)){
        glClearColor(0.01f, 0.13f, 0.11f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        triangle.Draw(GL_TRIANGLES);
        square.Draw(GL_TRIANGLE_FAN);

//        shaderProgram.Activate();
//        VAO1.Bind();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    triangle.Delete();
    square.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}