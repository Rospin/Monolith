#include <glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

#include "src\graphics\window\window.h"

#define DEBUG 1

#if DEBUG
	#define LOG(x)		std::cout << x << "\n";
#else
	#define LOG(x)
#endif

int main() {
	using namespace monolith;
	using namespace graphics;
	//Initialising GLFW
		if (!glfwInit()) {
		LOG("!!Failed to initialise GLFW");
	}else {
		LOG("Succesfully initiated GLFW");
	}
		Window window("Main Window", 960, 540);

	//Initialising GLEW
		if (glewInit() != GLEW_OK)
		{
			LOG("!!Failed to initialise GLEW");
		}else
		{
			LOG("Succesfully initiated GLEW");
		}

	//Program Loop
		while (!window.closed())
		{
			window.clear();
			if (window.isKeyPressed(GLFW_KEY_A))
				LOG("pressed A");
			window.update();
		}
	return 0;
}