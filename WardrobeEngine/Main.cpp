#include "MainDependencies.h"

int main() {

	auto &window	= Window::instance();
	auto &input		= Input::instance();
	auto &time		= Time::instance();

	window.init();
	input.init();
	time.init();
	

	while (window.step()) {
	
	}
	system("pause");

	window.terminte();
	
}