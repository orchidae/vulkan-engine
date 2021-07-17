#include "engine.h"

vk::Engine::Engine(uint32_t glfwExtensionCount, const char **glfwExtensions) {
    instance = new Instance(glfwExtensionCount, glfwExtensions);
}

vk::Engine::~Engine() {
    delete instance;
}
