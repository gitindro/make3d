cmake_minimum_required(VERSION 3.15)

project(make3d CXX)


find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(glbinding REQUIRED)
find_package(globjects REQUIRED)
find_package(globjects REQUIRED)
find_package(soil2 CONFIG REQUIRED)
find_package(assimp REQUIRED)
find_package(physfs CONFIG REQUIRED)
set(CMAKE_CXX_STANDARD 11)

include_directories(/external/loguru/)
include_directories(/src)
add_executable(make3d ./src/main.cpp ./external/loguru/loguru.cpp)
target_link_libraries(make3d
    PRIVATE glm::glm    
    PRIVATE glfw
    PRIVATE soil2
    PRIVATE physfs
    PUBLIC glbinding::glbinding
    PUBLIC globjects::globjects
    PUBLIC assimp
    )