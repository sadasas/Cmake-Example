cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial)

add_executable(Tutorial src/main.cpp)

add_subdirectory(src/Adder)

# download all the submodules
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# update submodules as needed
	option(GIT_SUBMODULES "Check submodules during build" ON)
	if(GIT_SUBMODULES)
		message(STATUS "Submodule Update")
		execute_process(COMMAND ${GIT EXECUTABLE} submodule update --init --recursive
						WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
						RESULT_VARIABLE GIT_SUBMODULE_RESULT)
		if(NOT GIT_SUBMOD_RESULT EQUAL "0")	
			message(FATAL_ERROR "git module update --init failed with ${GIT_SUBMOD_RESULT},please checkout submodule")
		endif()
	endif()
endif()

#CHECK ALL THE MODULES
if(NOT EXIST "${PROJECT_SOURCE_DIR}/external/glfw/CMakelists.txt")
	message(FATAL_EROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed ")
endif()

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

