add_library(${PROJECT_NAME} STATIC
        Renderer.cpp
)

# Namespace-Alias
add_library(Renderer::Renderer ALIAS Renderer)

# Füge Include-Verzeichnisse hinzu
target_include_directories(Renderer
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)