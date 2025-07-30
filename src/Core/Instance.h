#ifndef INSTANCE_H
#define INSTANCE_H

#include <vulkan/vulkan.hpp>

#include "Renderer/Renderer.h"

namespace Renderer::Core {
class Instance {
    const VkApplicationInfo appInfo;
    VkInstanceCreateInfo createInfo;
    VkInstance instance;

   public:
    Instance(const char* appName, Version version, uint32_t glfwExtensionCount,
             const char** glfwExtensions);
    ~Instance();

    void checkExtensionSupport() const;
};
}  // namespace Renderer

#endif  // INSTANCE_H
