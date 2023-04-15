#ifndef TANGRAM3D_MOUSEPICKER_H
#define TANGRAM3D_MOUSEPICKER_H

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "../camera/Camera.h"


struct MousePicker{

    glm::vec3 ray;
    glm::mat4 view;
    glm::mat4 projection;

    MousePicker();

    void UpdateMatrices(Camera& camera);
    void MouseInput(GLFWwindow* window, GLuint windowWidth, GLuint windowHeight);

private:
    glm::vec2 ViewPortToNormalized(double mouseX, double mouseY, GLuint windowWidth, GLuint windowHeight);
    glm::vec4 NormalizedToClip(glm::vec2 normalizedCoordinates);
    glm::vec4 ClipToEye(glm::vec4 clipCoordinates);
    glm::vec3 EyeToWorld(glm::vec4 eyeCoordinates);
};


#endif //TANGRAM3D_MOUSEPICKER_H
