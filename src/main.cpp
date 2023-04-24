#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game/Components.h"
#include "game/Figure.h"
#include "camera/Camera.h"

const GLuint WIDTH = 800;
const GLuint HEIGHT = 650;
const char* figureVertexSource = "../src/glsl/figure.vert";
const char* figureFragmentSource = "../src/glsl/figure.frag";
const char* figureTextureSource = "../resources/textures/Paper_cream.png";

int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "U3P3", nullptr, nullptr);

    if(window == nullptr){
        std::cout << "Error!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0, 0, WIDTH, HEIGHT);

    Figure triangle(figureVertexSource, figureFragmentSource, figureTextureSource,EQUILATERAL_TRIANGLE_VERTICES,
                    EQUILATERAL_TRIANGLE_INDICES, glm::vec3(0.0f, 0.0f, -5.0f), glm::mat4(1.0f));
    Figure square(figureVertexSource, figureFragmentSource, figureTextureSource,CUBE2D_VERTICES, CUBE2D_INDICES, glm::vec3(0.5, 0.5, -1.0),
    glm::mat4(1.0));

    Figure triangularPrisma(figureVertexSource, figureFragmentSource, figureTextureSource,TRIANGULAR_PRISMA_VERTICES, TRIANGULAR_PRISMA_INDICES, glm::vec3(1.5, 1.5, -1.0),
                  glm::mat4(1.0));


    Figure quadPrisma(figureVertexSource, figureFragmentSource, figureTextureSource,QUAD_PRISMA_VERTICES, QUAD_PRISMA_INDICES, glm::vec3(3.0, 1.5, -1.0),
                            glm::mat4(1.0));

    Figure pentagonalPrisma(figureVertexSource, figureFragmentSource, figureTextureSource,PENTAGONAL_PRISMA_VERTICES, PENTAGONAL_PRISMA_INDICES, glm::vec3(-3.0, 1.5, -1.0),
                      glm::mat4(1.0));

    Figure hexagonalPrisma(figureVertexSource, figureFragmentSource, figureTextureSource,HEXAGONAL_PRISMA_VERTICES, HEXAGONAL_PRISMA_INDICES, glm::vec3(-5.0, 1.5, -1.0),
                            glm::mat4(1.0));

    Figure triangularPyramid(figureVertexSource, figureFragmentSource, figureTextureSource,TRIANGULAR_PYRAMID_VERTICES, TRIANGULAR_PYRAMID_INDICES, glm::vec3(2.0, -1.5, -1.0),
                           glm::mat4(1.0));

    Figure quadPyramid(figureVertexSource, figureFragmentSource, figureTextureSource,QUAD_PYRAMID_VERTICES, QUAD_PYRAMID_INDICES, glm::vec3(5.0, -1.5, -1.0),
                             glm::mat4(1.0));

    Figure pentagonalPyramid(figureVertexSource, figureFragmentSource, figureTextureSource,PENTAGONAL_PYRAMID_VERTICES, PENTAGONAL_PYRAMID_INDICES, glm::vec3(-5.0, -1.5, -1.0),
                       glm::mat4(1.0));

    Figure hexagonalPyramid(figureVertexSource, figureFragmentSource, figureTextureSource,HEXAGONAL_PYRAMID_VERTICES, HEXAGONAL_PYRAMID_INDICES, glm::vec3(-3.0, -1.5, -1.0),
                             glm::mat4(1.0));

    Camera camera(WIDTH, HEIGHT, glm::vec3(0.0f, 0.0f, 1.0f));

    glEnable(GL_DEPTH_TEST);

    while(!glfwWindowShouldClose(window)){
        glClearColor(0.01f, 0.13f, 0.11f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        camera.Inputs(window);
        camera.UpdateMatrix(45.0f, 0.1f, 100.0f);

        triangularPrisma.Draw(GL_TRIANGLES, camera);
        quadPrisma.Draw(GL_TRIANGLES, camera);
        pentagonalPrisma.Draw(GL_TRIANGLES, camera);
        hexagonalPrisma.Draw(GL_TRIANGLES, camera);
        triangularPyramid.Draw(GL_TRIANGLES, camera);
        quadPyramid.Draw(GL_TRIANGLES, camera);
        pentagonalPyramid.Draw(GL_TRIANGLES, camera);
        hexagonalPyramid.Draw(GL_TRIANGLES, camera);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    triangle.Delete();
    square.Delete();
    triangularPrisma.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}