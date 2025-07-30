#include "Renderer/Renderer.h"

#include "./Core/Instance.h"

namespace Renderer {

class Renderer::Impl {
    Core::Instance* pInstance;

   public:
    Impl(const char* appName, const Version version, const uint32_t glfwExtensionCount,
         const char** glfwExtensions)
        : pInstance(new Core::Instance(appName, version, glfwExtensionCount, glfwExtensions)) {}

    ~Impl() { delete pInstance; }
};

Renderer::Renderer(const char* appName, const Version version, const uint32_t glfwExtensionCount,
                   const char** glfwExtensions)
    : pImpl(new Impl(appName, version, glfwExtensionCount, glfwExtensions)) {}

Renderer::~Renderer() { delete pImpl; }
}  // namespace Renderer