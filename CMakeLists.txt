cmake_minimum_required(VERSION 3.23)
project(Tangram3D)

set(CMAKE_CXX_STANDARD 14)

include_directories(includes/glm)
include_directories(includes/GLAD/include)
include_directories(includes/stb)

set(SOURCE_FILES src/main.cpp src/stb/stb.cpp includes/GLAD/src/glad.c src/camera/Camera.h src/camera/Camera.cpp src/game/Figure.h src/shader/Shader.h src/shader/Shader.cpp src/game/Tangram.h src/game/Figure.cpp)
set(OpenGlLinkers -lglfw)


add_executable(Tangram3D ${SOURCE_FILES})
target_link_libraries(Tangram3D ${OpenGlLinkers})