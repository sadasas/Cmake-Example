cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)

configure_file(TutorialConfig.h.in TutorialConfig.h)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

  
#adder
option(USE_ADDER "tes" ON)
if(USE_ADDER)
	add_subdirectory(src/Adder)
	list(APPEND EXTRA_LIBS_DIRS PUBLIC "src/adder")
	list(APPEND EXTRA_INCLUDES_DIRS "src/Adder")
	list(APPEND EXTRA_LINKS_DIRS adder)
	

endif()


# download all the submodules
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# update submodules as needed
	option(GIT_SUBMODULE "Check submodules during build" ON)
	if(GIT_SUBMODULE)
		message(STATUS "Submodule Update")
		execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
						WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
						RESULT_VARIABLE GIT_SUBMOD_RESULT)
		if(NOT GIT_SUBMOD_RESULT EQUAL "0")	
			message(FATAL_ERROR "git module update --init failed with ${GIT_SUBMOD_RESULT},please checkout submodule")
		endif()
	endif()
endif()

#CHECK ALL THE MODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakelists.txt")
	message(FATAL_EROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed ")
endif()

#glfw
add_subdirectory(external/glfw)
target_include_directories(
	${PROJECT_NAME} PUBLIC external/glfw/include
	${EXTRA_INCLUDES_DIRS})
	
target_link_directories(
	${PROJECT_NAME} PRIVATE external/glfw
	${EXTRA_LIBS_DIRS})

target_link_libraries(
	${PROJECT_NAME} PUBLIC glfw
	${EXTRA_LINKS_DIRS})

	install(TARGETS ${PROJECT_NAME} DESTINATION bin)
	install(FILES ${PROJECT_BINARY_DIR}/TutorialConfig.h DESTINATION include)