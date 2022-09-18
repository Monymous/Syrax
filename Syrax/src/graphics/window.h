#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#define GLEW_STATIC

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


namespace syrax{
	namespace graphics {

		class Window {
		private:
			int width, height;
			const char *name;
			GLFWwindow* window;

		public:
			Window(const char *name, int width, int height);
			~Window();
			void run();

		private:
			void clear();
			void init();
			void callback();
			void update();
			static void cursor_callback(GLFWwindow* window, double xPos, double yPos);
			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			static void mouse_callback(GLFWwindow* window, int button, int action, int mods);
		};

    }
}

#endif