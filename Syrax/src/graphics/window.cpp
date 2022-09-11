#include "window.h"

namespace syrax {
	namespace graphics {
		Window::Window(const char* name, int width, int height){
			this->name = name;
			this->width = width;
			this->height = height;
			this->init();
		}

		Window::~Window() {
			glfwDestroyWindow(this->window);
			glfwTerminate();
			delete this->window;
		}

		void Window::clear() {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::init() {
			if (!glfwInit()) {
				std::cout << "Failed to init GLFW\n";
				glfwTerminate();
			}

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			this->window = glfwCreateWindow(this->width, this->height, this->name, NULL, NULL);

			if (!this->window) {
				std::cout << "Failed to create GLFW window\n";
				glfwTerminate();
			}

			glfwMakeContextCurrent(this->window);
		}

		void Window::update() {
			glfwPollEvents();
			glfwGetFramebufferSize(this->window, &width, &height);
			glViewport(0, 0, this->width, this->height);
			glfwSwapBuffers(this->window);
		}
		
		void Window::run() {
			while (!glfwWindowShouldClose(this->window)) {
				glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
				this->clear();
				this->update();
			}
		}
	}
}