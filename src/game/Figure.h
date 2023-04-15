#ifndef TANGRAM3D_FIGURE_H
#define TANGRAM3D_FIGURE_H

#include "../shader/Shader.h"
#include "../camera/Camera.h"
#include "gtc/type_ptr.hpp"
#include <vector>

struct Figure {
   Shader shader;
   VAO vao;
   VBO vbo;
   EBO ebo;
   Texture texture;
   std::vector<Vertex> shape;
   std::vector<GLuint> indices;
   glm::vec3 position;
   glm::mat4 model;

   explicit Figure(const char* vertexSource, const char* fragmentSource, const char* textureSource,
                   std::vector<Vertex>& shape, std::vector<GLuint>& indices, glm::vec3 position, glm::mat4 model);


   void Draw(GLenum primitive, Camera& camera);
   void Translate(GLFWwindow* window);
   void Rotate();
   void Delete();

};

#endif //TANGRAM3D_FIGURE_H
