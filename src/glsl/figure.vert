#version 330 core

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexColor;
layout (location = 2) in vec2 vertexTexture;

out vec3 figureColor;
out vec2 figureTexture;

uniform mat4 cameraPosition;

void main() {
    gl_Position = cameraPosition * vec4(vertexPosition, 1.0);
    figureColor = vertexColor;
    figureTexture = vertexTexture;
}