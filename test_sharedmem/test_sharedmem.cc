#include "SharedMemory.h"
#include "Trace.h"
#include <iostream>
#include <stdexcept>

CLASS("unittest");

void read() {
	METHOD("read()");

	SharedMemory* mem = new SharedMemory("file.txt");
	mem->attach();
	std::cout << mem->read() << std::endl;
	mem->detach();
	delete mem;
}

void write() {
	METHOD("write()");

	SharedMemory* mem = new SharedMemory("file.txt");
	mem->attach();
	mem->update("hello world");
	std::cout << "size: " << mem->size() << std::endl;
	mem->detach();
	delete mem;

}

int main() {
	METHOD("main()");
	try {
		read();
		write();
	}
	catch(std::logic_error error) {
		std::cerr << "Exception: " << error.what() << std::endl;
		return 1;
	}
	return 0;
}

