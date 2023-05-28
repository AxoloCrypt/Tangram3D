#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <utility>
#include <thread>
#include <chrono>

#include "game/Tangram.h"
#include "game/Figure.h"
#include "game/MousePicker.h"
#include "game/Light.h"
#include "camera/Camera.h"

const GLuint WIDTH = 800;
const GLuint HEIGHT = 650;
const char* figureVertexSource = "../src/glsl/figure.vert";
const char* figureFragmentSource = "../src/glsl/figure.frag";
const char* lightVertexSource = "../src/glsl/light.vert";
const char* lightFragmentSource = "../src/glsl/light.frag";
const char* figureTextureSource = "../resources/textures/Paper_cream_grid_blue.png";
const char* tableTextureSource = "../resources/textures/planks.png";
const char* tableSpecularTextureSource = "../resources/textures/planksSpec.png";
const char* tangramFigureTextureSource = "../resources/textures/tangramFigure.jpg";

short CURRENT_TANGRAM = 0;
bool isLeftKeyPressed = false;
bool isRightKeyPressed = false;
bool switchingTangram = false;

struct Tangram{
    std::vector<Figure> figures;

    explicit Tangram(std::vector<Figure> figures);

    void Draw(GLenum primitive, Camera& camera, Light& light);
    void Delete();
};

void Tangram::Draw(GLenum primitive, Camera& camera, Light& light) {
    for(Figure figure : this->figures) {
        figure.Draw(primitive, camera, light);
    }
}

Tangram::Tangram(std::vector<Figure> figures) {
    this->figures = std::move(figures);
}

void Tangram::Delete() {
    for(Figure figure: this->figures){
        figure.Delete();
    }

    this->figures.clear();
}





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

    Figure bigTriangle(figureVertexSource, figureFragmentSource, figureTextureSource,BIG_TRIANGLE_VERTICES,
                    BIG_TRIANGLE_INDICES, glm::vec3(4.0f, -3.0f, -9.0f), glm::mat4(1.0f));

    Figure bigTriangle2(figureVertexSource, figureFragmentSource, figureTextureSource,BIG_TRIANGLE_VERTICES,
                    BIG_TRIANGLE_INDICES, glm::vec3(4.0f, -1.0f, -9.0f), glm::mat4(1.0f));

    Figure triangle(figureVertexSource, figureFragmentSource, figureTextureSource,EQUILATERAL_TRIANGLE_VERTICES,
                    EQUILATERAL_TRIANGLE_INDICES, glm::vec3(-4.0f, -3.0f, -9.0f), glm::mat4(1.0f));

    Figure triangle2(figureVertexSource, figureFragmentSource, figureTextureSource,EQUILATERAL_TRIANGLE_VERTICES,
                    EQUILATERAL_TRIANGLE_INDICES, glm::vec3(-4.0f, -1.0f, -9.0f), glm::mat4(1.0f));

    Figure mediumTriangle(figureVertexSource, figureFragmentSource, figureTextureSource, MEDIUM_TRIANGLE_VERTICES,
                          MEDIUM_TRIANGLE_INDICES, glm::vec3(-4.0f, 1.0f, -9.0f), glm::mat4(1.0f));

     Figure square(figureVertexSource, figureFragmentSource, figureTextureSource,SMALL_SQUARE_VERTICES, SQUARE_INDICES,
                  glm::vec3(0.0f, -2.5f, -9.0f), glm::mat4(1.0f));

    Figure table(figureVertexSource, "../src/glsl/figureSpecular.frag", tableTextureSource, tableSpecularTextureSource ,TABLE_VERTICES, TABLE_INDICES,
                 glm::vec3(0.0, 0.0, -5.0), glm::mat4(1.0));

    Figure rhomboid(figureVertexSource, "../src/glsl/figureSpecular.frag", figureTextureSource, RHOMBOID_VERTICES, ROMBHOID_INDICES,
                    glm::vec3(4.0, 1.0, -9.0), glm::mat4(1.0));

    Light light(lightVertexSource, lightFragmentSource, LIGHT_VERTICES, LIGHT_INDICES, glm::vec4(1.0, 1.0, 1.0, 1.0),
          glm::vec3(0.0, -6.0, 3.0), glm::mat4(1.0));

    Camera camera(WIDTH, HEIGHT, glm::vec3(0.0f, 0.0f, 1.0f));
    MousePicker mousePicker;

    Tangram teapot(std::vector<Figure> {
        Figure(figureVertexSource, figureFragmentSource, tangramFigureTextureSource, BIG_SQUARE_VERTICES,
               SQUARE_INDICES, glm::vec3(0.0f, 0.0f, -10.0f), glm::mat4(1.0f)), // Big Square
        Figure(figureVertexSource, figureFragmentSource, tangramFigureTextureSource, SMALL_SQUARE_VERTICES,
            SQUARE_INDICES, glm::vec3(-1.6f, 0.0f, -10.0f), glm::mat4(1.0f)), // Small Square
            Figure(figureVertexSource, figureFragmentSource, tangramFigureTextureSource, MEDIUM_TRIANGLE_VERTICES,
            MEDIUM_TRIANGLE_INDICES, glm::vec3(0.0f, 0.8f, -10.0f), glm::mat4(1.0f)), // Medium triangle

        Figure(figureVertexSource, figureFragmentSource, tangramFigureTextureSource, EQUILATERAL_TRIANGLE_VERTICES,
            EQUILATERAL_TRIANGLE_INDICES, glm::vec3(-1.3f, 0.5f, -10.0f), glm::mat4(1.0f)), // Small Triangle 1

        Figure(figureVertexSource, figureFragmentSource, tangramFigureTextureSource, EQUILATERAL_TRIANGLE_VERTICES,
            EQUILATERAL_TRIANGLE_INDICES, glm::vec3(-1.3f, -0.5f, -10.0f), glm::mat4(1.0f), 180), // Small Triangle 2

        Figure(figureVertexSource, figureFragmentSource, tangramFigureTextureSource, RHOMBOID_VERTICES,
            ROMBHOID_INDICES, glm::vec3(1.5f, -0.1f, -10.0f), glm::mat4(1.0f), 37), // Rhomboid
    });

    Tangram house(std::vector<Figure> {
        Figure (figureVertexSource, figureFragmentSource, tangramFigureTextureSource, SMALL_SQUARE_VERTICES,
            SQUARE_INDICES, glm::vec3(1.0f, 1.0f, -10.0f), glm::mat4(1.0f)), // Square
        Figure(figureVertexSource, figureFragmentSource, tangramFigureTextureSource, RHOMBOID_VERTICES,
            ROMBHOID_INDICES, glm::vec3(1.2, -0.1f, -10.0f), glm::mat4(1.0f), -45), //Rhomboid
        Figure(figureVertexSource, figureFragmentSource, tangramFigureTextureSource,BIG_TRIANGLE_VERTICES,
            BIG_TRIANGLE_INDICES, glm::vec3(0.55f, -0.45f, -10.0f), glm::mat4(1.0f)), // Triangle
        Figure(figureVertexSource, figureFragmentSource, tangramFigureTextureSource,RECTANGLE_VERTICES,
            RECTANGLE_INDICES, glm::vec3(1.0f, -1.9f, -10.0f), glm::mat4(1.0f)), // Rectangle
    });

    std::vector<Tangram> tangrams = {
            teapot, house
    };

    glEnable(GL_DEPTH_TEST);

    while(!glfwWindowShouldClose(window)){

        glClearColor(0.01f, 0.13f, 0.11f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        camera.Inputs(window);
        camera.UpdateMatrix(45.0f, 0.1f, 100.0f);

        light.Illuminate(camera);
        triangle.Draw(GL_TRIANGLES, camera, light);
        triangle2.Draw(GL_TRIANGLES, camera, light);
        bigTriangle.Draw(GL_TRIANGLES, camera, light);
        bigTriangle2.Draw(GL_TRIANGLES, camera, light);
        mediumTriangle.Draw(GL_TRIANGLES, camera, light);
        square.Draw(GL_TRIANGLE_FAN, camera, light);
        rhomboid.Draw(GL_TRIANGLES, camera, light);
        table.Draw(GL_TRIANGLES, camera, light);


        tangrams[CURRENT_TANGRAM].Draw(GL_TRIANGLES, camera, light);

        mousePicker.UpdateMatrices(camera);

        if(switchingTangram){
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "Test\n";
            light.ChangeColor(glm::vec4(1.0, 1.0, 1.0, 1.0));
            switchingTangram = false;
        }


        if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS && !isRightKeyPressed){
        }
        if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS && !isLeftKeyPressed){

            light.ChangeColor(glm::vec4(0.0, 0.0, 0.0, 1.0));
            switchingTangram = true;

            triangle.Restart();
            triangle2.Restart();
            bigTriangle.Restart();
            bigTriangle2.Restart();
            mediumTriangle.Restart();
            square.Restart();
            rhomboid.Restart();


            CURRENT_TANGRAM -= 1;

           if(CURRENT_TANGRAM < 0) {
               CURRENT_TANGRAM = (short) tangrams.size() - 1;
           }

            std::cout << CURRENT_TANGRAM << std::endl;
           isLeftKeyPressed = true;

        }

        if((glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_RELEASE) && isRightKeyPressed){
            isRightKeyPressed = false;
        }

        if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_RELEASE && isLeftKeyPressed){
            isLeftKeyPressed = false;
        }



        triangle.Translate(window, mousePicker);
        triangle.Rotate(window);
        triangle2.Translate(window, mousePicker);
        triangle2.Rotate(window);
        bigTriangle.Translate(window, mousePicker);
        bigTriangle.Rotate(window);
        bigTriangle2.Translate(window, mousePicker);
        bigTriangle2.Rotate(window);
        mediumTriangle.Translate(window, mousePicker);
        mediumTriangle.Rotate(window);
        square.Translate(window, mousePicker);
        square.Rotate(window);
        rhomboid.Translate(window, mousePicker);
        rhomboid.Rotate(window);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    triangle.Delete();
    triangle2.Delete();
    bigTriangle.Delete();
    bigTriangle2.Delete();
    square.Delete();
    table.Delete();
    rhomboid.Delete();
    light.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}