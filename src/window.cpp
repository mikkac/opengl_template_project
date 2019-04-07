#include "window.h"
#include <iostream>

namespace opengl
{
namespace // anonymous
{
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {}
} // anonymous namespace

Window::Window(const char* title, int width, int height)
    : m_title{title}, m_width{width}, m_height{height} {
    init();
    m_closed = glfwWindowShouldClose(m_window);
}

Window::~Window() noexcept {
    glfwTerminate();
}

bool Window::closed() const {
    return m_closed;
}

void Window::update() const {
    m_closed = glfwWindowShouldClose(m_window);
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void Window::clear(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::init() {
    if (!glfwInit()) { std::cerr << "unable to glfwInit()" << std::endl; }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
    if (not m_window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
    }
}

void error_callback(int error, const char* description) {
    puts(description);
}

} // namespace opengl
