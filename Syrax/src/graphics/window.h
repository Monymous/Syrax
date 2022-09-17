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
			void update();
		};

    }
}

#endif