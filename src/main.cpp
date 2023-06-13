
#define GLFW_INCLUDE_NONE
#include <glbinding/gl/gl.h>
#include <glbinding/glbinding.h>
#include <GLFW/glfw3.h>
#include "../external/loguru/loguru.hpp"
#include <SOIL2/SOIL2.h>

void __onLog(void* user_data, const loguru::Message& message)
{
    printf("[%s] %s %d %s", message.preamble, message.filename, message.line, message.message);
}


int main(void)
{
    GLFWwindow* window;

    loguru::add_file("core.log", loguru::Truncate, loguru::Verbosity_MAX);

    loguru::add_callback("engine_logger", __onLog, NULL, loguru::Verbosity_MAX);

    LOG_F(INFO, "App init --- Start of app");

    LOG_F(INFO, "Create Window");

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glbinding::initialize(glfwGetProcAddress);

    SOIL_save_screenshot("screen.png", SOIL_SAVE_TYPE_PNG, 0,0, 800, 600);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        gl::glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
        gl::glClear(gl::ClearBufferMask::GL_COLOR_BUFFER_BIT | gl::ClearBufferMask::GL_DEPTH_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}