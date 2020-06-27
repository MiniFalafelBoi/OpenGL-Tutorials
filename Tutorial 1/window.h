#pragma once

#include <GLFW/glfw3.h>

#include <iostream>

class Window {
	GLFWwindow* window;

public:
	Window(int width, int height, const char *caption) {
		// Initialize GLFW
		if (!glfwInit()) {
			glfwTerminate();
			std::cout << "ERROR::GLFW_INITIALIZATION_ERROR: glfw failed to initialize." << "\n";
		}
		
		// Window Hints
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

		glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

		// glfwWindowHint(GLFW_SAMPLES, 4);

		// Create Window
		window = glfwCreateWindow(width, height, caption, NULL, NULL);

		// Make Context Current
		glfwMakeContextCurrent(window);
	}

	int Run() {
		while (!glfwWindowShouldClose(window)) {
			// Render Loop

			glClearColor(0.1, 0.2, 0.2, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			// Draw Stuff

			glfwSwapBuffers(window);
			glfwPollEvents();

		}

		glfwTerminate();
		return 0;
	}
};