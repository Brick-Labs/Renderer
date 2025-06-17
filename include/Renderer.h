#ifndef RENDERER_H
#define RENDERER_H

#include <vulkan/vulkan.hpp>

struct Version {
    u_int32_t major;
    u_int32_t minor;
    u_int32_t patch;
};

class Renderer {
    VkInstance instance;
    const VkApplicationInfo appInfo;

   public:
    Renderer(char* appName, Version version)
        : appInfo(
              {.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
               .pApplicationName = appName,
               .applicationVersion = VK_MAKE_VERSION(version.major, version.minor, version.patch),
               .pEngineName = "BL-Renderer",
               .engineVersion = VK_MAKE_VERSION(0, 0, 1),
               .apiVersion = VK_API_VERSION_1_0}) {
        createInstance();
    }

    static void createInstance();
};

#endif  // RENDERER_H