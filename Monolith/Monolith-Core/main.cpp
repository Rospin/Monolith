#include <glew.h>
#include <GLFW\glfw3.h>
#include <cstdio>
#include <iostream>

#include "src\graphics\window\window.h"
#include "src\math\math.h"

#define DEBUG 1

#if DEBUG
	#define LOG(x)		printf("%s\n", x);
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

		math::mat4 position = math::mat4::translation(math::vec3(2, 3, 4));

	//Program Loop
		while (!window.closed())
		{
			window.clear();
			window.update();
		}
	return 0;
}