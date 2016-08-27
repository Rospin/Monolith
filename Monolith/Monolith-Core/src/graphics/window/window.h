#pragma once

#include <GLFW\glfw3.h>

namespace monolith {	namespace graphics {
	
#define	MAX_KEYS 1024
#define MAX_BUTTONS 32

	class Window {

	//Variables
		private:
			//Window Properties
				GLFWwindow *m_window;
				int m_width, m_height;
				const char *m_name;
				bool m_closed;

			//Input key arrays and mouse position
				static bool m_keys[MAX_KEYS];
				bool m_mouseButtons[MAX_BUTTONS];
				double m_mouseX, m_mouseY;
	//Functions
		public:
			//Constructor & deconstructor
				Window(const char *name, int width, int height);
				~Window();
			//Game loop
				void update();
				bool closed() const;
				void clear() const;
			//Input checking
				static bool isKeyPressed(int keyCode);
		private:
			//Initialisation
				void init();
			//Callbacks
				friend void window_resize_callback(GLFWwindow *window, int width, int height);
				friend void key_press_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};

} }