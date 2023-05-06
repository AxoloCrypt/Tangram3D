#version 330 core

out vec4 color;

in vec3 figureColor;
in vec2 figureTexture;
in vec3 figureNormal;
in vec3 figurePosition;

uniform sampler2D tex0;
uniform vec4 lightColor;
uniform vec3 lightPosition;
uniform vec3 cameraPosition;

void main() {

    float ambient = 0.20f;

    //diffuse
    vec3 normal = normalize(figureNormal);
    vec3 lightDirection = normalize(lightPosition - figurePosition);
    float diffuse = max(dot(normal, lightDirection), 0.0f);

    //specular
    float specularLight = 0.50f;
    vec3 viewDirection = normalize(cameraPosition - figurePosition);
    vec3 reflectionDirection = reflect(-lightDirection, normal);
    float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 8.0);
    float specular = specAmount * specularLight;


    color = texture(tex0, figureTexture) * lightColor * (diffuse + ambient + specular);
}