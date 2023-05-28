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


std::vector<Vertex> bigEquilateralTriangleVertices = {
        Vertex{glm::vec3(1.0, 0.0, -1.0), glm::vec3(1.0, 0.0, 0.0), glm::vec2(0.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(-1.0, 0.0, -1.0), glm::vec3(0.0, 1.0, 0.0), glm::vec2(0.0, 2.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(0.0, 1.0, -1.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2 (0.5, 2.4), glm::vec3(0.0, -1.0, 0.0)},
};

std::vector<GLuint> bigEquilateralTriangleIndices = {
        0, 1, 2,
};

std::vector<Vertex> mediumEquilateralTriangleVertices = {
        Vertex{glm::vec3(0.8, 0.0, -1.0), glm::vec3(1.0, 0.0, 0.0), glm::vec2(0.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(-0.8, 0.0, -1.0), glm::vec3(0.0, 1.0, 0.0), glm::vec2(0.0, 2.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(0.0, 0.8, -1.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2 (0.5, 2.4), glm::vec3(0.0, -1.0, 0.0)},
};

std::vector<GLuint> mediumEquilateralTriangleIndices = {
        0, 1, 2,
};

std::vector<Vertex> bigSquareVertices = {
        Vertex{glm::vec3(-0.8, -0.8, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(0.8, -0.8, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(-0.8, 0.8, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0, 0.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(0.8, 0.8, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 0.0), glm::vec3(0.0, -1.0, 0.0)},

        };

std::vector<Vertex> smallSquareVertices = {
        Vertex{glm::vec3(-0.5, -0.5, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(0.5, -0.5, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(-0.5, 0.5, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0, 0.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(0.5, 0.5, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 0.0), glm::vec3(0.0, -1.0, 0.0)},

};


std::vector<GLuint> squareIndices = {
    0, 1, 2,
    1, 3, 2,
};


std::vector<Vertex> rombhoidVertices = {
        Vertex{glm::vec3(-1.0, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0, 0.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(-0.5, 0.5, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(1.0, 0.5, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 0.0), glm::vec3(0.0, -1.0, 0.0)},
};

std::vector<GLuint> rombhoidIndices = {
        0, 1, 2,
        1, 3, 2,
};

std::vector<Vertex> tableVertices = {
        Vertex{glm::vec3(-7.0, -5.5, -6.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(7.0, -5.5, -6.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0, 0.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(-7.0, 6.0, -6.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(7.0, 6.0, -6.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 0.0), glm::vec3(0.0, -1.0, 0.0)},
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

std::vector<Vertex> rectangleVertices = {
        Vertex{glm::vec3(1.0, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(-1.0, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0, 0.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(1.0, 1.5, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0), glm::vec3(0.0, -1.0, 0.0)},
        Vertex{glm::vec3(-1.0, 1.5, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 0.0), glm::vec3(0.0, -1.0, 0.0)},
};

std::vector<GLuint> rectangleIndices = {
        0, 1, 2,
        1, 3, 2,
};


#define EQUILATERAL_TRIANGLE_VERTICES equilateralTriangleVertices
#define EQUILATERAL_TRIANGLE_INDICES equilateralTriangleIndices
#define SMALL_SQUARE_VERTICES smallSquareVertices
#define BIG_SQUARE_VERTICES bigSquareVertices
#define SQUARE_INDICES squareIndices
#define TABLE_VERTICES tableVertices
#define TABLE_INDICES tableIndices
#define LIGHT_VERTICES lightVertices
#define LIGHT_INDICES lightIndices
#define BIG_TRIANGLE_VERTICES bigEquilateralTriangleVertices
#define BIG_TRIANGLE_INDICES bigEquilateralTriangleIndices
#define MEDIUM_TRIANGLE_VERTICES mediumEquilateralTriangleVertices
#define MEDIUM_TRIANGLE_INDICES mediumEquilateralTriangleIndices
#define RHOMBOID_VERTICES rombhoidVertices
#define ROMBHOID_INDICES rombhoidIndices
#define RECTANGLE_VERTICES rectangleVertices
#define RECTANGLE_INDICES rectangleIndices


#endif //TANGRAM3D_TANGRAM_H
