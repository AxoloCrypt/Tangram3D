#ifndef TANGRAM3D_FIGURE_H
#define TANGRAM3D_FIGURE_H

#include "../shader/Shader.h"
#include "../camera/Camera.h"
#include "MousePicker.h"
#include "Light.h"
#include "gtc/type_ptr.hpp"
#include <vector>

struct Figure {
   Shader shader;
   VAO vao;
   VBO vbo;
   EBO ebo;
   Texture texture;
   Texture specularTexture;
   Texture* hasSpecular;
   std::vector<Vertex> shape;
   std::vector<GLuint> indices;
   glm::vec3 position;
   glm::vec3 originalPosition;
   glm::mat4 model;
   bool isPicked = false;
   float angle = 0.0f;


   explicit Figure(const char* vertexSource, const char* fragmentSource, const char* textureSource,
                   std::vector<Vertex>& shape, std::vector<GLuint>& indices, glm::vec3 position, glm::mat4 model);

   explicit Figure(const char* vertexSource, const char* fragmentSource, const char* textureSource,
                    std::vector<Vertex>& shape, std::vector<GLuint>& indices, glm::vec3 position, glm::mat4 model,
                    float angle);


   explicit Figure(const char* vertexSource, const char* fragmentSource, const char* textureSource,
                    const char* specularTextureSource,
                    std::vector<Vertex>& shape, std::vector<GLuint>& indices, glm::vec3 position, glm::mat4 model);

   void Draw(GLenum primitive, Camera& camera, Light& light);
   void Translate(GLFWwindow* window, MousePicker& mousePicker);
   void Rotate(GLFWwindow* window);
   void Delete();
   void Restart();

};

#endif //TANGRAM3D_FIGURE_H
