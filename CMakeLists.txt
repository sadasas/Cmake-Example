cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial)

add_executable(Tutorial src/main.cpp)

add_subdirectory(src/Adder)

add_subdirectory(external/glfw)

target_include_directories(Tutorial 
	PUBLIC src/Adder
	PUBLIC external/glfw/include	
	)

target_link_directories(Tutorial 
	PRIVATE src/Adder
	PRIVATE external/glfw/src
	)

target_link_libraries(Tutorial PUBLIC adder PUBLIC glfw)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(Tutorial PRIVATE imgui::imgui)

