#version 330 core

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexColor;
layout (location = 2) in vec2 vertexTexture;

out vec3 figureColor;
out vec2 figureTexture;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main() {
    vec4 worldPosition = modelMatrix * vec4(vertexPosition, 1.0);
    vec4 viewPosition = viewMatrix * worldPosition;
    gl_Position = projectionMatrix * viewPosition;
    figureColor = vertexColor;
    figureTexture = vertexTexture;
}