#version 330 core

out vec4 color;

in vec3 figureColor;

void main() {
    color = vec4(figureColor, 1.0);
}