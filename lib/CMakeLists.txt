add_subdirectory(glm)
add_subdirectory(Logger)

find_package(Vulkan REQUIRED)

target_link_libraries(Renderer PRIVATE glm::glm Logger::Logger Vulkan::Vulkan)