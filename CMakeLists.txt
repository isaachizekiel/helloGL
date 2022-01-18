cmake_minimum_required(VERSION 3.16)
project(cc_executable)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenGL REQUIRED)

add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/glad)


add_executable(cc_executable main.cpp)

target_link_libraries(cc_executable glad glfw)
