#include "window.h"

#include <stdexcept>

Window::Window() {
    glfwInit();

    if (glfwVulkanSupported() == GLFW_FALSE) {
        throw std::runtime_error("Vulkan not supported by the system");
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(windowWidth, windowHeight, "Vulkan Engine", nullptr, nullptr);

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    engine = new vk::Engine(glfwExtensionCount, glfwExtensions);
}

Window::~Window() {
    delete engine;

    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}
