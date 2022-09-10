#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <GLFW/glfw3.h>
#include <iostream>

namespace syrax{
	namespace graphics {

		class Window {
		private:
			long width, height;
			const char *name;
			GLFWwindow* window;

		public:
			Window(const char *name, long width, long height);
			~Window();
			void run();

		private:
			void update();
			void init();
		};

    }
}

#endif