#version 330 core

out vec4 color;

in vec3 figureColor;
in vec2 figureTexture;

uniform sampler2D tex0;

void main() {
    color = texture(tex0, figureTexture);
}