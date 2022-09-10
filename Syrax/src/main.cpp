#include "graphics/window.h"

int main() {
	using namespace syrax;
	using namespace graphics;

	Window window("Syrax", 800, 600);
	window.run();
	return 0;
}