#ifndef TANGRAM3D_FIGURE_H
#define TANGRAM3D_FIGURE_H

#include "../shader/Shader.h"
#include <vector>

struct Figure {
   Shader shader;
   VAO vao;
   VBO vbo;
   EBO ebo;
   Texture texture;
   std::vector<Vertex> shape;
   std::vector<GLuint> indices;

   explicit Figure(const char* vertexSource, const char* fragmentSource, const char* textureSource,std::vector<Vertex>& shape, std::vector<GLuint>& indices);


   void Draw(GLenum primitive);
   void Translate();
   void Rotate();
   void Delete();

};

#endif //TANGRAM3D_FIGURE_H
