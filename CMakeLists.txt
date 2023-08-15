cmake_minimum_required(VERSION 3.15)

project(make3d CXX)


find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(Vulkan REQUIRED)
find_package(assimp REQUIRED)
find_package(physfs CONFIG REQUIRED)
set(CMAKE_CXX_STANDARD 14)

include_directories(/external/loguru/)
include_directories(/src)
target_include_directories(glfw3)
add_executable(make3d ./src/main.cpp ./external/loguru/loguru.cpp ./src/engine.cpp ./src/M3DWindow.cpp ./src/AssetManager.cpp)
target_link_libraries(make3d
    PRIVATE glm::glm    
    PRIVATE glfw
    PRIVATE Vulkan::Vulkan
    PUBLIC assimp::assimp
    PRIVATE $<IF:$<TARGET_EXISTS:PhysFS::PhysFS>,PhysFS::PhysFS,PhysFS::PhysFS-static>
    )