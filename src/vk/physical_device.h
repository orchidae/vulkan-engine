#pragma once

#include <string>
#include <vulkan/vulkan.h>

namespace vk {

class PhysicalDevice {

public:
    explicit PhysicalDevice(VkPhysicalDevice physicalDevice);

    [[nodiscard]]
    std::string getName() const;

    [[nodiscard]]
    bool isDiscreteGpu() const;

private:
    VkPhysicalDevice handle = VK_NULL_HANDLE;
    VkPhysicalDeviceProperties physicalDeviceProperties{};
};

} // Namespace
