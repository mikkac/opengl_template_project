#include "window.h"
#include <glm/glm.hpp>

using namespace opengl;

int main() {
    constexpr int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;
    Window window{"simple", WINDOW_WIDTH, WINDOW_HEIGHT};

    while (not window.closed()) {
        window.clear(0.f, 0.f, 0.f, 1.0f);
        window.update();
    }
    return 0;
}
