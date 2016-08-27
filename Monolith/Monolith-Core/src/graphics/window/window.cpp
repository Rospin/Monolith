#include "window.h"
#include <iostream>
#include <GLFW\glfw3.h>

#define DEBUG 1

#if DEBUG
#define LOG(x)		std::cout << x << "\n";
#else
#define LOG(x)
#endif

namespace monolith {	namespace graphics {
	
	//Declaring static variables
		bool Window::m_keys[MAX_KEYS];
		bool Window::m_mouseButtons[MAX_BUTTONS];
		double Window::m_mouseX, Window::m_mouseY;
	
	//Constructor and deconstructor
		Window::Window(const char *name, int width, int height) 
	{
		m_name = name;
		m_width = width;
		m_height = height;
		m_closed = false;

		for (int i = 0; i < MAX_KEYS; i++)
			m_keys[i] = false;
		for (int i = 0; i < MAX_BUTTONS; i++)
			m_mouseButtons[i] = false;
		init();
	}

		Window::~Window()
	{
		glfwTerminate();
	}
			
	//Initialisation
		void Window::init() 
	{
		//Creating Window
			m_window = glfwCreateWindow(m_width, m_height, m_name, NULL, NULL);
			if (!m_window) 
			{
				LOG("!!Failed to create GLFW window");
			}else
			{ 
				LOG("Succesfully created GLFW window"); 
			}
			glfwMakeContextCurrent(m_window);

		//Setting callbacks
			//Window size modification
				glfwSetWindowSizeCallback(m_window, window_resize_callback);
			//Key pressing
				glfwSetWindowUserPointer(m_window, this);
				glfwSetKeyCallback(m_window, key_press_callback);
				glfwSetMouseButtonCallback(m_window, mouse_button_callback);
				glfwSetCursorPosCallback(m_window, cursor_position_callback);
	}
	
	//Game Loop functions
		bool Window::closed() const
	{
		return glfwWindowShouldClose(m_window);
	}

		void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

		void Window::update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	//Callback functions

		void window_resize_callback(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

		void key_press_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer;
			win->m_keys[key] = action != GLFW_RELEASE;
		}

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer;
			win->m_mouseButtons[button] = action != GLFW_RELEASE;
		}

		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer;
			win->m_mouseX = xpos;
			win->m_mouseY = ypos;
		}
	//Input functions
		bool Window::isKeyPressed(int keyCode) const
		{
			if (keyCode >= 1024)		LOG("!!Keycode exceeds max number of keys");
			return m_keys[keyCode];
		}

		bool Window::isMouseButtonPressed(int button) const
		{
			if (button >= 32)		LOG("!!ButtonCode exceeds max number of buttons");
			return m_mouseButtons[button];
		}

		void Window::getMousePosition(double& x, double&y) const
		{
			x = m_mouseX;
			y = m_mouseY;
		}
} }