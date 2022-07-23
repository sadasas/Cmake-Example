#include <iostream>
#include "adder.h"
#include "GLFW/glfw3.h"
#include "TutorialConfig.h"

int main(int argc, char* argv[])
{

	std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."<< Tutorial_VERSION_MINOR << "\n";

	GLFWwindow *window;
	if(!glfwInit())
		exit(EXIT_FAILURE);
	
	window = glfwCreateWindow(400,400,"First",NULL,NULL);
	glfwSwapInterval(1);

	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwWaitEvents();
	}
	glfwTerminate();
	exit(EXIT_SUCCESS);

	return 0;
}
