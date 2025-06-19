#ifndef RENDERER_H
#define RENDERER_H
#include <cstdint>
#include <string>

namespace Renderer {

struct Version {
    uint32_t major;
    uint32_t minor;
    uint32_t patch;
};

class Renderer {
    // IMPL-idiom (Pointer to Implementation) is used hide the vulkan datatypes from the application
    class Impl;
    Impl* pImpl;

   public:
    Renderer(const char* appName, Version version, uint32_t glfwExtensionCount,
             const char** glfwExtensions);
    ~Renderer();
};

}  // namespace Renderer

#endif  // RENDERER_H