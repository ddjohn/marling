#include "Trace.h"
#include <iostream>
#include <stdexcept>
#include <unistd.h>
//#include <WebSocket.h>
#include <Serial.h>
#include <string.h>

CLASS("");

int main(int args, char* argv[]) {
	METHOD("main()");


	try {
//WebSocket socket(8888);
//socket.run();

Serial serial("/dev/ttyACM1", BAUD9600);

char buf[] = "Hello world";
int length = strlen(buf);
serial.tx(buf, length);

while(serial.rx(buf, length) == false);

std::cout << ": " << buf << " (" << length << ")" << std::endl;

	}
	catch(std::logic_error error) {
		std::cerr << "Exception: " << error.what() << std::endl;
		return 1;
	}
	return 0;
}

