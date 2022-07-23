cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial)

add_executable(Tutorial src/main.cpp)

add_subdirectory(src/Adder)

target_include_directories(Tutorial PUBLIC src/Adder)

target_link_directories(Tutorial PRIVATE src/Adder)

target_link_libraries(Tutorial PUBLIC adder)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(Tutorial PRIVATE imgui::imgui)

