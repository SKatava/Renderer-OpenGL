#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <renderer/Renderer.h>

int main() {
    if (!glfwInit()) {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_SAMPLES, 4);

    glfwWindowHint(GLFW_DECORATED, GL_FALSE);


    GLFWwindow* window = glfwCreateWindow(800, 800, "Renderer Example", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwSwapInterval(0);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    }

    Renderer renderer;
    renderer.Init();


    while (!glfwWindowShouldClose(window)) {
        renderer.Render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

