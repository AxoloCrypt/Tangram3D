#include "Light.h"

#include <utility>

Light::Light(const char *vertexSource, const char *fragmentSource, std::vector<LightVertex> lightVertices,
             std::vector<GLuint> lightIndices, glm::vec4 color, glm::vec3 position, glm::mat4 model) {

    this->color = color;
    this->position = position;
    this->model = model;
    this->indices = std::move(lightIndices);

    this->model = glm::translate(this->model, this->position);

    shader = Shader(vertexSource, fragmentSource);
    vao.Bind();

    vbo = VBO(lightVertices);
    ebo = EBO(indices);

    vao.LinkAttribute(vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), nullptr);

    vao.Unbind();
    vbo.Unbind();
    ebo.Unbind();


}

void Light::Illuminate(Camera& camera) {
    shader.Activate();
    vao.Bind();
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "viewMatrix"), 1, GL_FALSE, glm::value_ptr(camera.view));
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projectionMatrix"), 1, GL_FALSE, glm::value_ptr(camera.projection));
    glUniform4f(glGetUniformLocation(shader.ID, "lightColor"), color.x, color.y, color.z, color.w);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
}

void Light::Delete() {
    vao.Delete();
    vbo.Delete();
    ebo.Delete();
    shader.Delete();
}

void Light::ChangeColor(glm::vec4 newColor) {
    color = newColor;
}
