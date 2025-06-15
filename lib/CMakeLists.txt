add_subdirectory(glm)

find_package(Vulkan REQUIRED)

target_link_libraries(Renderer PRIVATE glm::glm Vulkan::Vulkan)