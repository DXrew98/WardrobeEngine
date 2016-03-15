#include "MainDependencies.h"

int main() {

	auto &window = Window::instance();

	window.init();

	while (window.step()) {
		system("pause");
	}
	window.terminte();
	
}