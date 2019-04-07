#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace opengl
{
class Window
{
  public:
    Window(const char* title, int width, int height);
    ~Window() noexcept;
    bool closed() const;
    void update() const;
    void clear(float r, float g, float b, float a);
    GLFWwindow* get_window_ptr() const { return m_window; }

  private:
    void init();

  private: //!
    GLFWwindow* m_window;
    const char* m_title;
    int m_width;
    int m_height;
    mutable bool m_closed;
};

void error_callback(int error, const char* description);

} // namespace opengl