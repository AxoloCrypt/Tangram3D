#ifndef TANGRAM3D_SHADER_H
#define TANGRAM3D_SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <vector>


#include "glm.hpp"
#include "stb_image.h"

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
    glm::vec2 texture;
    glm::vec3 normal;
};

struct LightVertex {
    glm::vec3 position;
};

struct VBO{
    GLuint ID;

    VBO();
    VBO(std::vector<Vertex>& vertices);
    VBO(std::vector<LightVertex>& lightVertices);

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

struct Texture{
    GLuint ID;


    Texture();
    Texture(const char* source, GLenum slot);

    void TextureUnit(Shader& shader, const char* uniform, GLuint unit);
    void Bind();
    void Unbind();
    void Delete();

};


#endif //TANGRAM3D_SHADER_H
