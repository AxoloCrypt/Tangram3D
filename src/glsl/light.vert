#version 330 core

layout (location = 0) in vec3 position;

uniform mat4 model;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main(){
    vec4 worldPosition = model * vec4(position, 1.0);
    vec4 viewPosition = viewMatrix * worldPosition;
    gl_Position = projectionMatrix * viewPosition;
}