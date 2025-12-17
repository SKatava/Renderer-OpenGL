# examples/CMakeLists.txt

add_executable(renderer_example main.cpp)

# Link GLFW
find_package(glfw3 REQUIRED)

target_link_libraries(renderer_example
    PRIVATE
        renderer
        glfw
)

target_compile_features(renderer_example PRIVATE cxx_std_20)

