#include "Trace.h"
#include <iostream>
//#include <stdexcept>
#include <unistd.h>
#include <Serial.h>
#include <string.h>
#include <thread>
#include <mutex>

CLASS("");

std::mutex mutex;

Serial* serial;
void input() {
	std::cout << "--- thread: input  ---" << std::endl;

	char buf[256];
	int length;

	while(1) {
		sleep(1);

		std::cout << "> " << std::flush;
		std::string command;
		std::getline(std::cin, command);
		sprintf(buf, "%s\r\n", command.c_str()); 
		length = strlen(buf);
		serial->tx(buf, length);
	}
}


int main(int args, char* argv[]) {
	METHOD("main()");

	try {
		sleep(1);
		serial = new Serial("/dev/ttyUSB0", BAUD115200);

		std::thread t1(input);

		sleep(1);

		char buf[256];
		int length;
		while(1) {
			buf[0] = '\0';
			while(serial->rx(buf, length) == false) sleep(1);
			buf[length] = '\0';
			std::cout << buf;
		}
		t1.join();
	}
	catch(std::logic_error error) {
		std::cerr << "Exception: " << error.what() << std::endl;
		return 1;
	}
	return 0;
}

