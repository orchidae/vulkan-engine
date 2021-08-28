#include <stdexcept>
#include <vector>

#include "instance.h"
#include "debug.h"

vk::Instance::Instance(uint32_t glfwExtensionCount, const char** glfwExtensions) {
    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);
    std::vector<const char*> layers;
#ifndef NDEBUG
    extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    layers.push_back("VK_LAYER_KHRONOS_validation");
#endif

    VkApplicationInfo applicationInfo{
        .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pApplicationName = "Vulkan Engine",
        .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
        .pEngineName = "",
        .engineVersion = VK_MAKE_VERSION(1, 0, 0),
        .apiVersion = VK_API_VERSION_1_0
    };

    VkInstanceCreateInfo instanceCreateInfo{
        .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pApplicationInfo = &applicationInfo,
        .enabledLayerCount = static_cast<uint32_t>(layers.size()),
        .ppEnabledLayerNames = layers.data(),
        .enabledExtensionCount = static_cast<uint32_t>(extensions.size()),
        .ppEnabledExtensionNames = extensions.data()
    };

#ifndef NDEBUG
    VkDebugUtilsMessengerCreateInfoEXT debugUtilsMessengerCreateInfo{
        .sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,
        .messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT
            | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,
        .messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT
            | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT
            | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,
        .pfnUserCallback = debugUtilsMessengerCallback
    };
    instanceCreateInfo.pNext = &debugUtilsMessengerCreateInfo;
#endif

    if (vkCreateInstance(&instanceCreateInfo, nullptr, &handle) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance!");
    }
#ifndef NDEBUG
    if (CreateDebugUtilsMessengerEXT(handle, &debugUtilsMessengerCreateInfo, nullptr, &debugMessenger) != VK_SUCCESS) {
        throw std::runtime_error("failed to set up debug messenger!");
    }
#endif
}

vk::Instance::~Instance() {
#ifndef NDEBUG
    DestroyDebugUtilsMessengerEXT(handle, debugMessenger, nullptr);
#endif
    vkDestroyInstance(handle, nullptr);
}

std::vector<VkPhysicalDevice> vk::Instance::getPhysicalDevices() {
    uint32_t count = 0;
    VkResult result = vkEnumeratePhysicalDevices(handle, &count, nullptr);
    if (result != VK_SUCCESS) {
        return {};
    }
    std::vector<VkPhysicalDevice> physicalDevices(count);
    result = vkEnumeratePhysicalDevices(handle, &count, physicalDevices.data());
    if (result != VK_SUCCESS) {
        return {};
    }
    return physicalDevices;
}
