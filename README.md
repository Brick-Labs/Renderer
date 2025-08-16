# Renderer

This project aims to develop a real-time, cross-platform renderer focused on rendering digital bricks with high visual
quality and performance. The goal is to create a flexible rendering engine that can be integrated into different
applications in the future.

> [!IMPORTANT]
> This renderer cannot be used independently, only with programs that make use of it.

## Requirements
> [!TIP]
> A block model refers to a list of building blocks, including their positions and colors.

### Functional Requirements
- [ ] Initialization of the renderer instance and transfer of settings.
- [ ] Load the scene data created by the program that implements this library. This data includes the camera and light positions, as well as the block model and backround information.
- [ ] Render building blocks models, there are no plans to support any other type of 3D model.
- [ ] Write the output to a given imgae buffer.
- [ ] Handle different brick materials, like standard plastic, transparent or glowing.
- [ ] Implement focus blur for camera.
- [ ] Lights in various sizes, colors, and temperatures should be supported.
- [ ] Support for various art styles during rendering, including realistic and retro. [PicoCad](https://store.steampowered.com/app/2800590/picoCAD) can serve as inspiration for the retro style.

### Non-Functional Requirements
- [ ] Efficient memory usage, each brick should only exist once in memory.
- [ ] Every importent action should be logged.

## Setup
1. Install Vulkan SDK from this [Website](https://vulkan.lunarg.com).
2. Add this repo as submodule to the project `git submodule add https://github.com/Brick-Labs/Renderer.git` and clone submodules recursively `git submodule update --init --recursive`
