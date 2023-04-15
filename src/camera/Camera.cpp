
#include "Camera.h"

Camera::Camera(GLint width, GLint height, glm::vec3 position) {
    this->width = width;
    this->height = height;
    this->position = position;
}

void Camera::UpdateMatrix(float fovDegree, float nearPlane, float farPlane) {
    view = glm::lookAt(position, position + orientation, up);
    projection = glm::perspective(glm::radians(fovDegree), (float)width / height, nearPlane, farPlane);
}

void Camera::Matrix(Shader &shader) {
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "viewMatrix"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projection));
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
