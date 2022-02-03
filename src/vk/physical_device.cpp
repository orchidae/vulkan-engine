#include "physical_device.h"

vk::PhysicalDevice::PhysicalDevice(VkPhysicalDevice physicalDevice) :
    handle(physicalDevice) {
    vkGetPhysicalDeviceProperties(handle, &physicalDeviceProperties);
}

std::string vk::PhysicalDevice::getName() const {
    return physicalDeviceProperties.deviceName;
}

bool vk::PhysicalDevice::isDiscreteGpu() const {
    return physicalDeviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU;
}
