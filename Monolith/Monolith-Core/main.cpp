#include <glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

#include "src\graphics\window\window.h"
#include "src\math\vec2\vec2.h"

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

		math::vec2 vector(1.0f, 2.0f);
		vector = (vector + math::vec2(2.0f, 4.0f) - math::vec2(2.0f, 3.0f)) * math::vec2(5.0f, 7.0f) / math::vec2(2.0f, 2.0f);
		std::cout << vector << "\n";

	//Program Loop
		while (!window.closed())
		{
			window.clear();
			window.update();
		}
	return 0;
}