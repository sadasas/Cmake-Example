#include <iostream>
#include "adder.h"
#include "GLFW/glfw3.h"

int main()
{
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
