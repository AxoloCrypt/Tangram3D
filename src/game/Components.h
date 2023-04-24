#ifndef TANGRAM3D_COMPONENTS_H
#define TANGRAM3D_COMPONENTS_H

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

std::vector<Vertex> TRIANGULAR_PRISMA_VERTICES = {
        Vertex{glm::vec3(0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(-0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.0, 0.5, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.5, 0.0, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(-0.5, 0.0, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.0, 0.5, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
};

std::vector<GLuint> TRIANGULAR_PRISMA_INDICES = {
        0, 1, 2,
        3, 4, 5,
        0, 3, 4,
        1, 3, 4,
        2, 4, 5,
        2, 3, 4,
        3, 0, 1,
        4, 0, 1,
        4, 2, 1,
        5, 2, 1,
        5, 0, 2,
};

std::vector<Vertex> QUAD_PRISMA_VERTICES = {
        Vertex{glm::vec3(-0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.5, 1.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(-0.5, 1.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(-0.5, 0.0, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.5, 0.0, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.5, 1.0, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(-0.5, 1.0, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
};


std::vector<GLuint> QUAD_PRISMA_INDICES = {
        0, 2, 1,
        3, 0, 2,
        4, 6, 5,
        7, 4, 6,
        0, 4, 5,
        1, 4, 5,
        4, 0, 1,
        5, 0, 1,
        1, 6, 5,
        6, 2, 1,
        0, 7, 4,
        7, 3, 0,
};

std::vector<Vertex> PENTAGONAL_PRISMA_VERTICES = {
        Vertex{glm::vec3(-0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0 ,1.0)},
        Vertex{glm::vec3(0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0 ,1.0)},
        Vertex{glm::vec3(0.0, 0.5, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0 ,1.0)},
        Vertex{glm::vec3(-0.75, 0.55, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0 ,1.0)},
        Vertex{glm::vec3(0.0, 1.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0 ,1.0)},
        Vertex{glm::vec3(0.75, 0.55, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0 ,1.0)},

        Vertex{glm::vec3(-0.5, 0.0, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0 ,1.0)},
        Vertex{glm::vec3(0.5, 0.0, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0 ,1.0)},
        Vertex{glm::vec3(0.0, 0.5, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0 ,1.0)},
        Vertex{glm::vec3(-0.75, 0.55, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0 ,1.0)},
        Vertex{glm::vec3(0.0, 1.0, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0 ,1.0)},
        Vertex{glm::vec3(0.75, 0.55, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0 ,1.0)},
};

std::vector<GLuint> PENTAGONAL_PRISMA_INDICES = {
        0, 1, 2,
        0, 2, 3,
        1, 2, 5,
        2, 3, 4,
        2, 5, 4,

        6, 7, 8,
        6, 8, 9,
        7, 8, 11,
        8, 9, 10,
        8, 11, 10,

        0, 6, 7,
        1, 6, 7,
        6, 0, 1,
        7, 0, 1,
        1, 11, 7,
        11, 5, 1,
        5, 10, 11,
        11, 4, 5,
        0, 9, 6,
        9, 3, 0,
        3, 10, 9,
        9, 4, 3,
        4, 9, 10,
        10, 3, 4,
};


std::vector<Vertex> HEXAGONAL_PRISMA_VERTICES = {
        Vertex{glm::vec3(-0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.0, 0.5, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(-0.75, 0.55, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.75, 0.55, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.5, 1.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(-0.5, 1.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},

        Vertex{glm::vec3(-0.5, 0.0, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.5, 0.0, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.0, 0.5, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(-0.75, 0.55, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.75, 0.55, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.5, 1.0, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(-0.5, 1.0, -3.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},

};

std::vector<GLuint> HEXAGONAL_PRISMA_INDICES = {
        0, 1, 2,
        0, 2, 3,
        1, 2, 4,
        3, 2, 6,
        4, 2, 5,
        6, 5, 2,

        7, 8, 9,
        7, 9, 10,
        8, 9, 11,
        10, 9, 13,
        11, 9, 12,
        13, 12, 9,

        0, 8, 7,
        8, 1, 0,
        0, 10, 7,
        10, 3, 0,
        3, 13, 10,
        13, 6, 3,
        5, 12, 13,
        13, 6, 5,
        4, 10, 12,
        12, 5, 4,
        1, 11, 8,
        11, 4, 1,
};

std::vector<Vertex> TRIANGULAR_PYRAMID_VERTICES = {
        Vertex{glm::vec3(-0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.0, 0.0, -2.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.0, 1.0, -1.4), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
};

std::vector<GLuint> TRIANGULAR_PYRAMID_INDICES = {
        0, 1, 2,
        0, 1, 3,
        0, 2, 3,
        1, 2, 3,
};

std::vector<Vertex> QUAD_PYRAMID_VERTICES = {
        Vertex{glm::vec3(-0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(-0.5, 0.0, -2.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.5, 0.0, -2.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.0, 1.0, -1.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
};

std::vector<GLuint> QUAD_PYRAMID_INDICES = {
        0, 1, 3,
        0, 2, 3,
        0, 1, 4,
        1, 3, 4,
        0, 2, 4,
        2, 3, 4,
};

std::vector<Vertex> PENTAGONAL_PYRAMID_VERTICES = {
        Vertex{glm::vec3(-0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.0, 0.0, -1.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(-0.75, 0.0, -2.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.0, 0.0, -2.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.75, 0.0, -2.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.0, 1.0, -1.75), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
};

std::vector<GLuint> PENTAGONAL_PYRAMID_INDICES = {
        0, 1, 2,
        0, 2, 3,
        1, 2, 5,
        3, 2, 4,
        4, 2, 5,

        0, 1, 6,
        0, 3, 6,
        3, 4, 6,
        1, 5, 6,
};

std::vector<Vertex> HEXAGONAL_PYRAMID_VERTICES = {
        Vertex{glm::vec3(-0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.5, 0.0, -1.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.0, 0.0, -1.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(-0.75, 0.0, -1.55), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.75, 0.0, -1.55), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.5, 0.0, -2.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(-0.5, 0.0, -2.0), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},
        Vertex{glm::vec3(0.0, 1.0, -1.5), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0, 1.0)},

};

std::vector<GLuint> HEXAGONAL_PYRAMID_INDICES = {
        0, 1, 2,
        0, 2, 3,
        1, 2, 4,
        2, 3, 6,
        2, 4, 5,
        5, 6, 2,
        0, 1, 7,
        0, 3, 7,
        3, 6, 7,
        1, 4, 7,
        4, 6, 7,
        5, 6, 7,
};


#endif //TANGRAM3D_COMPONENTS_H
