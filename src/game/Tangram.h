#ifndef TANGRAM3D_TANGRAM_H
#define TANGRAM3D_TANGRAM_H

#include "../shader/Shader.h"

 std::vector<Vertex> EQUILATERAL_TRIANGLE_VERTICES = {
        Vertex{glm::vec3(0.5, 0.0, -1.0), glm::vec3(1.0, 0.0, 0.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(-0.5, 0.0, -1.0), glm::vec3(0.0, 1.0, 0.0), glm::vec2(0.0, 2.0)},
        Vertex{glm::vec3(0.0, 0.5, -1.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2 (0.5, 2.4)},
};

 std::vector<GLuint> EQUILATERAL_TRIANGLE_INDICES = {
        0, 1, 2,
};

std::vector<Vertex> CUBE2D_VERTICES = {
        Vertex{glm::vec3(-0.5, -0.5, -1.0), glm::vec3(1.0, 0.0, 0.0), glm::vec2(0.0, 0.0)},
        Vertex{glm::vec3(0.5, 0.5, -1.0), glm::vec3(0.0, 1.0, 0.0), glm::vec2(0.0, 1.0f)},
        Vertex{glm::vec3(-0.5, 0.5, -1.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(1.0, 0.0)},
        Vertex{glm::vec3(-0.5, 0.5, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0, 1.0)},
        Vertex{glm::vec3(0.5, -0.5, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0, 0.0)},
        Vertex{glm::vec3(0.5, 0.5, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0, 1.0)},
};

std::vector<GLuint> CUBE2D_INDICES = {
        0, 1, 2, 3, 4, 5
};

std::vector<Vertex> TABLE_VERTICES = {
        Vertex{glm::vec3(-6.0, -2.5, -6.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0, 1.0)},
        Vertex{glm::vec3(6.0, -2.5, -6.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0, 0.0)},
        Vertex{glm::vec3(-6.0, 5.0, -6.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(6.0, 5.0, -6.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 0.0)},
};

std::vector<GLuint> TABLE_INDICES = {
        0, 1, 2,
        1, 3, 2,
};

#define EQUILATERAL_TRIANGLE_VERTICES EQUILATERAL_TRIANGLE_VERTICES
#define EQUILATERAL_TRIANGLE_INDICES EQUILATERAL_TRIANGLE_INDICES
#define SQUARE_VERTICES CUBE2D_VERTICES
#define SQUARE_INDICES CUBE2D_INDICES
#define TABLE_VERTICES TABLE_VERTICES
#define TABLE_INDICES TABLE_INDICES

#endif //TANGRAM3D_TANGRAM_H
