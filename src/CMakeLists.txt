add_library(${PROJECT_NAME} STATIC
        Renderer.cpp
        Core/Instance.cpp
)

# Namespace-Alias
add_library(Renderer::Renderer ALIAS Renderer)

# Add Include-Path
target_include_directories(Renderer
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)