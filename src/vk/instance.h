#pragma once

#include <vector>
#include <vulkan/vulkan.h>
#include "physical_device.h"

namespace vk {

class Instance {
public:
    Instance(uint32_t glfwExtensionCount, const char** glfwExtensions);
    ~Instance();

    std::vector<PhysicalDevice> getPhysicalDevices();

private:
    VkInstance handle = VK_NULL_HANDLE;
    VkDebugUtilsMessengerEXT debugMessenger{};
};

} // Namespace


