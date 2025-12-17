cmake_minimum_required(VERSION 3.31.1)

project(renderer LANGUAGES C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#Glad from source
add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

#library 
add_library(renderer
    src/renderer/VAO.cpp
    src/renderer/VBO.cpp
    src/renderer/Shader_program.cpp
    src/renderer/Shader.cpp
    src/renderer/Logger.cpp
    src/renderer/Renderer.cpp
    src/renderer/Mesh.cpp
)

target_include_directories(renderer
    PUBLIC
        include
    PRIVATE
        src
)

#link glad
target_link_libraries(renderer PUBLIC glad)

#link OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(renderer PUBLIC OpenGL::GL)

#link OpenGL mathematics
find_package(glm CONFIG REQUIRED)
target_link_libraries(renderer PRIVATE glm::glm)


#Enable errors
target_compile_options(renderer PRIVATE -Wall -Wextra -Wpedantic)

#examples subdir
option(BUILD_EXAMPLES "Build example applications" ON)

if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
