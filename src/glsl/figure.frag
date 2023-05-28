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


vec4 spotLight(){

    float outerCone = 0.90f;
    float innerCone = 0.95f;


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

    float angle = dot(vec3(0.0f, -1.0, 0.0), -lightDirection);
    float intern = clamp((angle - outerCone) / (innerCone  - outerCone), 0.0, 1.0f);


    return (texture(tex0, figureTexture) * (diffuse * intern + ambient + specular * intern) * lightColor);
}

vec4 directLight(){

    float ambient = 0.20f;

    //diffuse
    vec3 normal = normalize(figureNormal);
    vec3 lightDirection = normalize(vec3(1.0, 1.0, 0.0));
    float diffuse = max(dot(normal, lightDirection), 0.0f);

    //specular
    float specularLight = 0.50f;
    vec3 viewDirection = normalize(cameraPosition - figurePosition);
    vec3 reflectionDirection = reflect(-lightDirection, normal);
    float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 8.0);
    float specular = specAmount * specularLight;

    return (texture(tex0, figureTexture) * lightColor * (diffuse + ambient + specular));
}

vec4 defaultLight(){
    float ambient = 0.02f;

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


    return texture(tex0, figureTexture) * lightColor * (diffuse + ambient + specular);
}

void main() {
    color = defaultLight();
}