
#ifndef TANGRAM3D_LIGHT_H
#define TANGRAM3D_LIGHT_H

#include "../shader/Shader.h"
#include <gtc/type_ptr.hpp>
#include "../camera/Camera.h"

struct Light {
    Shader shader;
    VAO vao;
    VBO vbo;
    EBO ebo;
    glm::vec4 color{};
    glm::vec3 position{};
    glm::mat4 model{};
    std::vector<GLuint> indices;

    Light(const char* vertexSource, const char* fragmentSource, std::vector<Vertex> lightVertices, std::vector<GLuint> lightIndices,
          glm::vec4 color, glm::vec3 position, glm::mat4 model);

    void Illuminate(Camera& camera);
    void Delete();

};

#endif //TANGRAM3D_LIGHT_H
