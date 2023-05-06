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

#endif //TANGRAM3D_TANGRAM_H
