
#include "Camera.h"

Camera::Camera(GLint width, GLint height, glm::vec3 position) {
    this->width = width;
    this->height = height;
    this->position = position;
}

void Camera::UpdateMatrix(float fovDegree, float nearPlane, float farPlane) {
    // Initializes matrices since otherwise they will be the null matrix
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    // Makes camera look in the right direction from the right position
    view = glm::lookAt(position, position + orientation, up);
    // Adds perspective to the scene
    projection = glm::perspective(glm::radians(fovDegree), (float)width / height, nearPlane, farPlane);

    // Sets new camera matrix
    matrix = projection * view;
}

void Camera::Matrix(Shader &shader, const char* uniform) {
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Camera::Inputs(GLFWwindow* window) {

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        position += speed * orientation;
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        position += speed * -glm::normalize(glm::cross(orientation, up));
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        position += speed * -orientation;
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        position += speed * glm::normalize(glm::cross(orientation, up));
    }

}
