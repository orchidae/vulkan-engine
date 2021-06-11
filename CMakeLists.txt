cmake_minimum_required(VERSION 3.19)
project(vulkan-engine)

set(CMAKE_CXX_STANDARD 20)

# Vulkan
find_package(Vulkan REQUIRED)

add_executable(vulkan-engine main.cpp)

target_link_libraries(vulkan-engine PRIVATE Vulkan::Vulkan)