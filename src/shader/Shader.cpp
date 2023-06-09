#include "Shader.h"


std::string GetFileContents(const char* filename){
    std::ifstream in(filename, std::ios::binary);
    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return(contents);
    }
    throw(errno);
}

void CompileErrors(unsigned int shader, const char* type){
    GLint hasCompiled;
    char infoLog[1024];

    if(type != "PROGRAM"){
        glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
        if(hasCompiled == GL_FALSE){
            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            std::cout << "SHADER_COMPILATION_ERROR for: " << type << "\n" << std::endl;
        }
    }else{
        glGetProgramiv(shader, GL_COMPILE_STATUS, &hasCompiled);
        if(hasCompiled == GL_FALSE){
            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            std::cout << "SHADER_LINKING_ERROR for: " << type << "\n" << std::endl;
        }
    }
}

Shader::Shader(const char *vertexFile, const char *fragmentFile) {
    std::string vertexCode = GetFileContents(vertexFile);
    std::string  fragmentCode = GetFileContents(fragmentFile);

    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();


    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
    glCompileShader(vertexShader);
    CompileErrors(vertexShader, "VERTEX");

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
    glCompileShader(fragmentShader);
    CompileErrors(fragmentShader, "FRAGMENT");

    ID = glCreateProgram();

    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);
    CompileErrors(ID, "PROGRAM");

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Activate() {
    glUseProgram(ID);
}

void Shader::Delete() {
    glDeleteProgram(ID);
}

Shader::Shader() = default;


VBO::VBO(std::vector<Vertex> &vertices) {
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex) , vertices.data(), GL_STATIC_DRAW);
}

VBO::VBO(std::vector<LightVertex>& lightVertices) {
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, lightVertices.size() * sizeof(LightVertex), lightVertices.data(), GL_STATIC_DRAW);
}

void VBO::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete() {
    glDeleteBuffers(1, &ID);
}


VBO::VBO() = default;

VAO::VAO() {
    glGenVertexArrays(1, &ID);
}

void VAO::LinkAttribute(VBO VBO, GLuint layout, GLint numComponent, GLenum type, GLsizeiptr stride, void *offset) {
    VBO.Bind();
    glVertexAttribPointer(layout, numComponent, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

void VAO::Bind() {
    glBindVertexArray(ID);
}

void VAO::Unbind() {
    glBindVertexArray(0);
}

void VAO::Delete() {
    glDeleteVertexArrays(1, &ID);
}

EBO::EBO(std::vector<GLuint> &indices) {
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}

void EBO::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete() {
    glDeleteBuffers(1, &ID);
}

EBO::EBO() = default;

Texture::Texture() = default;

Texture::Texture(const char *source, GLenum slot) {
    int width, height, numCol;

    unsigned char* bytes = stbi_load(source, &width, &height, &numCol, 0);

    glGenTextures(1, &ID);
    glActiveTexture(slot);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_NEAREST);

    if(numCol == 4)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
    else if(numCol == 3)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, bytes);
    else if(numCol == 1)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,GL_RED, GL_UNSIGNED_BYTE, bytes);
    else
        throw std::invalid_argument("Automatic Texture type recognition failed");

    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(bytes);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Bind() {
    glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete() {
    glDeleteTextures(1, &ID);
}

void Texture::TextureUnit(Shader &shader, const char *uniform, GLuint unit) {
    GLuint textureUnit = glGetUniformLocation(shader.ID, uniform);
    shader.Activate();
    glUniform1i(textureUnit, unit);
}
