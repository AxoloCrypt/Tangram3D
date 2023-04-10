#ifndef TANGRAM3D_SHADER_H
#define TANGRAM3D_SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include "glm.hpp"
#include <vector>

std::string GetFileContents(const char* filename);
void CompileErrors(unsigned int shader, const char* type);


struct Shader{
    GLuint ID;

    Shader();
    Shader(const char* vertexFile, const char* fragmentFile);

    void Activate();
    void Delete();

};

struct Vertex {
    glm::vec3 position;
    glm::vec3 color;
};


struct VBO{
    GLuint ID;

    VBO();
    VBO(std::vector<Vertex>& vertices);

    void Bind();
    void Unbind();
    void Delete();
};


struct VAO {
    GLuint ID;

    VAO();

    void LinkAttribute(VBO VBO, GLuint layout, GLint numComponent, GLenum type, GLsizeiptr stride, void* offset);
    void Bind();
    void Unbind();
    void Delete();

};


struct EBO{
    GLuint ID;

    EBO();
    EBO(std::vector<GLuint>& indices);

    void Bind();
    void Unbind();
    void Delete();

};

#endif //TANGRAM3D_SHADER_H