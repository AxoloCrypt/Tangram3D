#include "MousePicker.h"

#include <cmath>

MousePicker::MousePicker() = default;

void MousePicker::UpdateMatrices(Camera &camera) {
    view = camera.view;
    projection = camera.projection;
    origin = camera.position;
}

//void MousePicker::MouseInput(GLFWwindow *window, GLuint windowWidth, GLuint windowHeight) {
//
//    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
//        double x;
//        double y;
//
//        glfwGetCursorPos(window, &x, &y);
//
//        glm::vec3 worldCoordinates = ViewPortToWorld(x, y, windowWidth, windowHeight);
//
//        std::cout << "World x: " << worldCoordinates.x << " World y: " << worldCoordinates.y << " World z: "
//        << worldCoordinates.z << "\n";
//
//    }
//
//}

glm::vec3 MousePicker::ViewPortToWorld(double mouseX, double mouseY, GLuint windowWidth, GLuint windowHeight) {

    glm::vec4 clipCoordinates = NormalizedToClip(ViewPortToNormalized(mouseX, mouseY, windowWidth, windowHeight));
    glm::vec4 eyeCoordinates = ClipToEye(clipCoordinates);

    return EyeToWorld(eyeCoordinates);
}

glm::vec2 MousePicker::ViewPortToNormalized(double mouseX, double mouseY, GLuint windowWidth, GLuint windowHeight) {

    float normalizedX = (2.0f * (float) mouseX) / (float) windowWidth - 1.0f;
    float normalizedY = 1.0f - (2.0f * (float) mouseY) / (float) windowHeight;

    return {normalizedX, normalizedY};
}

glm::vec4 MousePicker::NormalizedToClip(glm::vec2 normalizedCoordinates) {
    return {normalizedCoordinates.x, normalizedCoordinates.y, -1.0f, 1.0f};
}

glm::vec4 MousePicker::ClipToEye(glm::vec4 clipCoordinates) {
    glm::vec4 ray_eye = glm::inverse(projection) * clipCoordinates;
    return {ray_eye.x, ray_eye.y, -1.0f, 0.0f};
}

glm::vec3 MousePicker::EyeToWorld(glm::vec4 eyeCoordinates) {
    glm::vec3 world = glm::inverse(view) * eyeCoordinates;
    return glm::normalize(world);
}

bool MousePicker::rayIntersects(glm::vec3 origin, glm::vec3 ray, glm::vec3 sphereCenter, float sphereRadius) {

    glm::vec3 distanceSphere = origin - sphereCenter;
    float b = glm::dot(ray, distanceSphere);
    float c = glm::dot(distanceSphere, distanceSphere) - sphereRadius * sphereRadius;

    float t = b * b - c;


    std::cout << "t = " << t << "\n";

    if(t == 0.0f){
       float rootT = -b +  std::sqrt(t);

       if(rootT < 0.0f)
           return false;

    }

    return t > 0.0f;
}
