#include "Figure.h"

Figure::Figure(const char* vertexSource, const char* fragmentSource, std::vector<Vertex>& shape, std::vector<GLuint>& indices) {

    this->shader = Shader(vertexSource, fragmentSource);
    this->shape = shape;
    this->indices = indices;

    vao.Bind();

    vbo = VBO(this->shape);
    ebo = EBO(this->indices);

    vao.LinkAttribute(vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), nullptr);
    vao.LinkAttribute(vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    vao.Unbind();
    vbo.Unbind();
    ebo.Unbind();

}

void Figure::Draw(GLenum primitive){
    shader.Activate();
    vao.Bind();
    glDrawElements(primitive, indices.size(), GL_UNSIGNED_INT, 0);
}

void Figure::Translate() {
}

void Figure::Rotate() {

}

void Figure::Delete() {
    vao.Delete();
    vbo.Delete();
    ebo.Delete();
    shader.Delete();
}