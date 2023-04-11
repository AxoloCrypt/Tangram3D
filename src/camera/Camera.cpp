
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

    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
        glfwSetInputMode(window, GLFW_CURSOR,GLFW_CURSOR_HIDDEN);

        if(firstClick){
            glfwSetCursorPos(window, (width / 2), (height / 2));
            firstClick = false;
        }

        double mouseX;
        double mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);

        float rotX = sensitivity * (float)(mouseY - (height/2)) / height;
        float rotY = sensitivity * (float)(mouseX - (height/2)) / width;

        glm::vec3 newOrientation = glm::rotate(orientation, glm::radians(-rotX),
                                               glm::normalize(glm::cross(orientation, up)));

        if(std::abs(glm::angle(newOrientation, up) - glm::radians(90.0f)) <= glm::radians(85.0f)){
            orientation = newOrientation;
        }

        orientation = glm::rotate(orientation, glm::radians(-rotY), up);

        glfwSetCursorPos(window, (width / 2), (height / 2));
    }
    else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        firstClick = true;
    }

}
