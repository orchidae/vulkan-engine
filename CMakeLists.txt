cmake_minimum_required(VERSION 3.19)
project(vulkan-engine)

set(CMAKE_CXX_STANDARD 20)

add_executable(vulkan-engine src/main.cpp src/vk/instance.cpp src/vk/instance.h
        src/window.cpp src/window.h src/vk/engine.cpp src/vk/engine.h src/vk/debug.h)

# Vulkan
find_package(Vulkan REQUIRED)

# GLFW
set(GLFW_BUILD_DOCS OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_EXAMPLES OFF)
add_subdirectory(lib/glfw)
target_include_directories(vulkan-engine PUBLIC /lib/glfw/include)

# GLM
target_include_directories(vulkan-engine PUBLIC lib/glm)

target_link_libraries(vulkan-engine PUBLIC Vulkan::Vulkan glfw)