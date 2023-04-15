#include "MousePicker.h"

MousePicker::MousePicker() = default;

void MousePicker::UpdateMatrices(Camera &camera) {
    view = camera.view;
    projection = camera.projection;
}

void MousePicker::MouseInput(GLFWwindow *window, GLuint windowWidth, GLuint windowHeight) {

    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
        double x;
        double y;

        glfwGetCursorPos(window, &x, &y);


        glm::vec4 clipCoordinates = NormalizedToClip(ViewPortToNormalized(x, y, windowWidth, windowHeight));
        glm::vec4 eyeCoordinates = ClipToEye(clipCoordinates);
        glm::vec3 worldCoordinates = EyeToWorld(eyeCoordinates);

        std::cout << "World x: " << worldCoordinates.x << " World y: " << worldCoordinates.y << " World z: "
        << worldCoordinates.z << "\n";

    }

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
    return glm::inverse(projection) * clipCoordinates;
}

glm::vec3 MousePicker::EyeToWorld(glm::vec4 eyeCoordinates) {
    glm::vec3 world = glm::inverse(view) * eyeCoordinates;
    return glm::normalize(world);
}
