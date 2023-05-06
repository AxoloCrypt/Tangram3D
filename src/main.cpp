#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game/Tangram.h"
#include "game/Figure.h"
#include "game/MousePicker.h"
#include "camera/Camera.h"

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

    Figure triangle(figureVertexSource, figureFragmentSource, figureTextureSource,EQUILATERAL_TRIANGLE_VERTICES,
                    EQUILATERAL_TRIANGLE_INDICES, glm::vec3(-2.0f, -2.0f, -5.0f), glm::mat4(1.0f));
    Figure square(figureVertexSource, figureFragmentSource, figureTextureSource,SQUARE_VERTICES, SQUARE_INDICES,
                  glm::vec3(-0.5f, -1.5f, -5.0f), glm::mat4(1.0f));

    Figure table(figureVertexSource, figureFragmentSource, "../resources/textures/planks.png", TABLE_VERTICES, TABLE_INDICES,
                 glm::vec3(0.0, 0.0, -5.0), glm::mat4(1.0));

    Camera camera(WIDTH, HEIGHT, glm::vec3(0.0f, 0.0f, 1.0f));
    MousePicker mousePicker;

    glEnable(GL_DEPTH_TEST);

    while(!glfwWindowShouldClose(window)){
        glClearColor(0.01f, 0.13f, 0.11f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        camera.Inputs(window);
        camera.UpdateMatrix(45.0f, 0.1f, 100.0f);

        triangle.Draw(GL_TRIANGLES, camera);
        square.Draw(GL_TRIANGLE_FAN, camera);
        table.Draw(GL_TRIANGLES, camera);

        mousePicker.UpdateMatrices(camera);

        triangle.Translate(window, mousePicker);
        square.Translate(window, mousePicker);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    triangle.Delete();
    square.Delete();
    table.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}