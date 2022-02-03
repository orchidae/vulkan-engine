#include "engine.h"
#include <iostream>

vk::Engine::Engine(uint32_t glfwExtensionCount, const char **glfwExtensions) {
    instance = new Instance(glfwExtensionCount, glfwExtensions);
    for (const auto& device : instance->getPhysicalDevices()) {
        std::cout << device.getName() << " " << device.isDiscreteGpu() << std::endl;
    }
}

vk::Engine::~Engine() {
    delete instance;
}
