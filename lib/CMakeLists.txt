add_subdirectory(glm)
add_subdirectory(spdlog)

find_package(Vulkan REQUIRED)

target_link_libraries(Renderer PRIVATE glm::glm spdlog::spdlog Vulkan::Vulkan)