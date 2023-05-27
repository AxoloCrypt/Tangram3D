#include "Figure.h"

Figure::Figure(const char* vertexSource, const char* fragmentSource, const char* textureSource,
               std::vector<Vertex>& shape, std::vector<GLuint>& indices, glm::vec3 position, glm::mat4 model) {

    this->shader = Shader(vertexSource, fragmentSource);
    this->shape = shape;
    this->indices = indices;
    this->texture = Texture(textureSource, 0);
    this->position = position;
    this-> model = model;

    this->model = glm::translate(this->model, this->position);

    hasSpecular = nullptr;

    vao.Bind();

    vbo = VBO(this->shape);
    ebo = EBO(this->indices);

    vao.LinkAttribute(vbo, 0, 3, GL_FLOAT, 11 * sizeof(float), nullptr);
    vao.LinkAttribute(vbo, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
    vao.LinkAttribute(vbo, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
    vao.LinkAttribute(vbo, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

    vao.Unbind();
    vbo.Unbind();
    ebo.Unbind();

}


Figure::Figure(const char *vertexSource, const char *fragmentSource, const char *textureSource,
               const char *specularTextureSource, std::vector<Vertex> &shape, std::vector<GLuint> &indices,
               glm::vec3 position, glm::mat4 model) {

    this->shader = Shader(vertexSource, fragmentSource);
    this->shape = shape;
    this->indices = indices;
    this->texture = Texture(textureSource, 0);
    this->specularTexture = Texture(specularTextureSource, 1);
    this->position = position;
    this-> model = model;

    this->model = glm::translate(this->model, this->position);

    hasSpecular = &this->specularTexture;

    vao.Bind();

    vbo = VBO(this->shape);
    ebo = EBO(this->indices);

    vao.LinkAttribute(vbo, 0, 3, GL_FLOAT, 11 * sizeof(float), nullptr);
    vao.LinkAttribute(vbo, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
    vao.LinkAttribute(vbo, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
    vao.LinkAttribute(vbo, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

    vao.Unbind();
    vbo.Unbind();
    ebo.Unbind();
}


void Figure::Draw(GLenum primitive, Camera& camera, Light& light){
    texture.TextureUnit(shader, "tex0", 0);

    if(hasSpecular != nullptr){
        specularTexture.TextureUnit(shader, "tex1", 1);
    }

    shader.Activate();
    texture.Bind();
    vao.Bind();
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "viewMatrix"), 1, GL_FALSE, glm::value_ptr(camera.view));
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projectionMatrix"), 1, GL_FALSE, glm::value_ptr(camera.projection));
    glUniform4f(glGetUniformLocation(shader.ID, "lightColor"), light.color.x, light.color.y, light.color.z, light.color.w);
    glUniform3f(glGetUniformLocation(shader.ID, "lightPosition"), light.position.x, light.position.y, light.position.z);
    glUniform3f(glGetUniformLocation(shader.ID, "cameraPosition"), camera.position.x, camera.position.y, camera.position.z);
    glDrawElements(primitive, indices.size(), GL_UNSIGNED_INT, 0);
}

void Figure::Translate(GLFWwindow* window, MousePicker& mousePicker) {

    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){

        double mouseX;
        double mouseY;

        glfwGetCursorPos(window, &mouseX, &mouseY);

        int windowWidth;
        int windowHeight;

        glfwGetWindowSize(window, &windowWidth, &windowHeight);

        glm::vec3 mouseWorld = mousePicker.ViewPortToWorld(mouseX, mouseY, windowWidth, windowHeight);


//        std::cout << "Mouse world x: " << mouseWorld.x << " Mouse world y: " << mouseWorld.y << " Mouse world z: " <<
//        mouseWorld.z << std::endl;

        if (isPicked){
            model = glm::mat4(1.0);
            position = glm::vec3(mouseWorld.x * 8.5, mouseWorld.y * 8.5, position.z);
            model = glm::translate(position);
            model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0, 0.0, 1.0));
        }

        if(MousePicker::rayIntersects(mousePicker.origin, mouseWorld, position, 0.35f)){
            isPicked = true;
            texture = Texture("../resources/textures/Paper_cream.png", 0);
        }


    }

    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE){
        if (isPicked){
            isPicked = false;
        }
    }

}

void Figure::Rotate(GLFWwindow* window) {

    if(glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS){
       if(isPicked){
           std::cout << angle << "\n";
            angle += 1.0f;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0, 0.0, 1.0));
       }
    }

    if(glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS){
        if(isPicked){
            std::cout << angle << "\n";
            angle -= 1.0f;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0, 0.0, 1.0));
        }
    }
}

void Figure::Delete() {
    vao.Delete();
    vbo.Delete();
    ebo.Delete();
    texture.Delete();
    shader.Delete();
}

