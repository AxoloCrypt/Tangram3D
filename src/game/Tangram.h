#ifndef TANGRAM3D_TANGRAM_H
#define TANGRAM3D_TANGRAM_H

#include "../shader/Shader.h"

 std::vector<Vertex> equilateralTriangleVertices = {
        Vertex{glm::vec3(0.5, 0.0, -1.0), glm::vec3(1.0, 0.0, 0.0), glm::vec2(0.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(-0.5, 0.0, -1.0), glm::vec3(0.0, 1.0, 0.0), glm::vec2(0.0, 2.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(0.0, 0.5, -1.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2 (0.5, 2.4), glm::vec3(0.0, -1.0, 0.0)},
};

 std::vector<GLuint> equilateralTriangleIndices = {
        0, 1, 2,
};

std::vector<Vertex> squareVertices = {
        Vertex{glm::vec3(-0.5, -0.5, -1.0), glm::vec3(1.0, 0.0, 0.0), glm::vec2(0.0, 0.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(0.5, 0.5, -1.0), glm::vec3(0.0, 1.0, 0.0), glm::vec2(0.0, 1.0f), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(-0.5, 0.5, -1.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(1.0, 0.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(-0.5, 0.5, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(0.5, -0.5, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0, 0.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(0.5, 0.5, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
};

std::vector<GLuint> squareIndices = {
        0, 1, 2, 3, 4, 5
};

std::vector<Vertex> tableVertices = {
        Vertex{glm::vec3(-6.0, -2.5, -6.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(6.0, -2.5, -6.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0, 0.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(-6.0, 5.0, -6.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(6.0, 5.0, -6.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 0.0), glm::vec3(0.0, -1.0, 0.0)},
};

std::vector<GLuint> tableIndices = {
        0, 1, 2,
        1, 3, 2,
};

std::vector<LightVertex> lightVertices = {
        LightVertex{glm::vec3(-0.5, 0.0, -1.0)},
        LightVertex{glm::vec3(0.5, 0.0, -1.0)},
        LightVertex{glm::vec3(-0.5, 1.0, -1.0)},
        LightVertex{glm::vec3(0.5, 1.0, -1.0)},


        LightVertex{glm::vec3(-0.5, 0.0, -2.0)},
        LightVertex{glm::vec3(0.5, 0.0, -2.0)},
        LightVertex{glm::vec3(-0.5, 1.0, -2.0)},
        LightVertex{glm::vec3(0.5, 1.0, -2.0)},
};

std::vector<GLuint> lightIndices = {
        0, 1, 2,
        1, 3, 2,

        4, 5, 6,
        5, 7, 6,

        0, 4, 6,
        6, 2, 0,

        1, 5, 7,
        7, 3, 1,
};

#define EQUILATERAL_TRIANGLE_VERTICES equilateralTriangleVertices
#define EQUILATERAL_TRIANGLE_INDICES equilateralTriangleIndices
#define SQUARE_VERTICES squareVertices
#define SQUARE_INDICES squareIndices
#define TABLE_VERTICES tableVertices
#define TABLE_INDICES tableIndices
#define LIGHT_VERTICES lightVertices
#define LIGHT_INDICES lightIndices



#endif //TANGRAM3D_TANGRAM_H
