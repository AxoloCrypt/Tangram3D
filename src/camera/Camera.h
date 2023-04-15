#ifndef TANGRAM3D_CAMERA_H
#define TANGRAM3D_CAMERA_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../shader/Shader.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "gtx/rotate_vector.hpp"
#include "gtx/vector_angle.hpp"



struct Camera{
    glm::vec3 position;
    glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::mat4 projection = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);


    GLint width;
    GLint height;

    float speed = 0.1f;
    float sensitivity = 100.0f;

    Camera(GLint width, GLint height, glm::vec3 position);
    void UpdateMatrix(float fovDegree, float nearPlane, float farPlane);
    void Matrix(Shader& shader);
    void Inputs(GLFWwindow* window);

};

#endif //TANGRAM3D_CAMERA_H
