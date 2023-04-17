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

    vao.Bind();

    vbo = VBO(this->shape);
    ebo = EBO(this->indices);

    vao.LinkAttribute(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), nullptr);
    vao.LinkAttribute(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    vao.LinkAttribute(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    vao.Unbind();
    vbo.Unbind();
    ebo.Unbind();

}

void Figure::Draw(GLenum primitive, Camera& camera){
    texture.TextureUnit(shader, "tex0", 0);
    shader.Activate();
    texture.Bind();
    vao.Bind();
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "viewMatrix"), 1, GL_FALSE, glm::value_ptr(camera.view));
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projectionMatrix"), 1, GL_FALSE, glm::value_ptr(camera.projection));
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



        if(MousePicker::rayIntersects(mousePicker.origin, mouseWorld, position, 0.5f)){

//            position.x += mouseWorld.x;
//            position.y += mouseWorld.y;

            texture = Texture("../resources/textures/Paper_cream.png", 0);

//            model = glm::translate(model, glm::vec3(mouseWorld.x, mouseWorld.y, 0.0f));
        }

    }

}

void Figure::Rotate() {

}

void Figure::Delete() {
    vao.Delete();
    vbo.Delete();
    ebo.Delete();
    texture.Delete();
    shader.Delete();
}