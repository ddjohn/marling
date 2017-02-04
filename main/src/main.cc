#include "Trace.h"
#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <person.pb.h>

CLASS("");

int main(int args, char* argv[]) {
	METHOD("main()");

	try {
	}
	catch(std::logic_error error) {
		std::cerr << "Exception: " << error.what() << std::endl;
		return 1;
	}
	return 0;
}

