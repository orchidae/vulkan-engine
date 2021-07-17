#pragma once

#include "instance.h"

namespace vk {

class Engine {
public:
    Engine(uint32_t glfwExtensionCount, const char** glfwExtensions);
    ~Engine();

private:
    Instance* instance;
};

} // Namespace


