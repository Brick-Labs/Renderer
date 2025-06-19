#include "Renderer/Renderer.h"

#include <iostream>
#include <vulkan/vulkan.hpp>

namespace Renderer {

class Renderer::Impl {
    const VkApplicationInfo appInfo;
    VkInstanceCreateInfo createInfo;
    VkInstance instance;

   public:
    Impl(const char* appName, const Version version, const uint32_t glfwExtensionCount,
         const char** glfwExtensions)
        : appInfo(
              {.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
               .pApplicationName = appName,
               .applicationVersion = VK_MAKE_VERSION(version.major, version.minor, version.patch),
               .pEngineName = "BL-Renderer",
               .engineVersion = VK_MAKE_VERSION(0, 0, 1),
               .apiVersion = VK_API_VERSION_1_0}),
          createInfo({.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                      .pApplicationInfo = &appInfo,
                      .enabledExtensionCount = glfwExtensionCount,
                      .ppEnabledExtensionNames = glfwExtensions,
                      .enabledLayerCount = 0}) {
        checkExtensionSupport();
        // Start macOS support
        std::vector<const char*> requiredExtensions;

        requiredExtensions.reserve(glfwExtensionCount);
        for (uint32_t i = 0; i < glfwExtensionCount; i++) {
            requiredExtensions.emplace_back(glfwExtensions[i]);
        }

        requiredExtensions.emplace_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);

        createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;

        createInfo.enabledExtensionCount = static_cast<uint32_t>(requiredExtensions.size());
        createInfo.ppEnabledExtensionNames = requiredExtensions.data();
        // End macOS support

        if (const VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
            result != VK_SUCCESS) {
            throw std::runtime_error("Failed to create Vulkan instance! Error: " +
                                     std::to_string(result));
        }
    }

    ~Impl() { vkDestroyInstance(instance, nullptr); }

    void checkExtensionSupport() const {
        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

        std::vector<VkExtensionProperties> extensions(extensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

        std::vector<VkExtensionProperties> missingExtensions;

        std::cout << "Available extensions:";
        for (const auto& extension : extensions) {
            std::cout << "\n- " << extension.extensionName;
        }

        // Find the missing extensions
        for (uint32_t i = 0; i < createInfo.enabledExtensionCount; i++) {
            const char* extensionName = createInfo.ppEnabledExtensionNames[i];
            bool found = false;

            for (const auto& extension : extensions) {
                if (strcmp(extension.extensionName, extensionName) == 0) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                VkExtensionProperties missingExt = {};
                strcpy(missingExt.extensionName, extensionName);
                missingExtensions.push_back(missingExt);
            }
        }

        if (!missingExtensions.empty()) {
            std::string errorMessage = "Missing extensions:";
            for (const auto& missingExtension : missingExtensions) {
                errorMessage += std::string("\n- ", missingExtension.extensionName);
            }
            throw std::runtime_error(errorMessage);
        }
    }
};

Renderer::Renderer(const char* appName, const Version version, const uint32_t glfwExtensionCount,
                   const char** glfwExtensions)
    : pImpl(new Impl(appName, version, glfwExtensionCount, glfwExtensions)) {}

Renderer::~Renderer() { delete pImpl; }

}  // namespace Renderer