#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "vk/engine.h"

class Window {
public:
    Window();
    ~Window();

    void mainLoop();

private:
    GLFWwindow* window;
    const int windowWidth = 800;
    const int windowHeight = 600;

    vk::Engine* engine;
};


