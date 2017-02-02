#include "Trace.h"
#include <iostream>
#include <stdexcept>

CLASS("");

int main() {
	METHOD("main()");
	try {
	}
	catch(std::logic_error error) {
		std::cerr << "Exception: " << error.what() << std::endl;
		return 1;
	}
	return 0;
}

