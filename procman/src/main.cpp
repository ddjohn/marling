#include <Program.h>
#include <Trace.h>
#include <string>
#include <iostream>

CLASS("");

void syntax(std::string process) {
	METHOD("syntax(std::strimg)");

	std::cout << std::endl;
	std::cout << "syntax: " << process << " [start|stop|restart|status] [process]" << std::endl;
}

int main(int args, char* argv[]) {
	METHOD("main()");

	std::string process = argv[0];

	if(args != 3) {
		syntax(process);
		return 1;
	}

	std::string command = argv[1];
	std::string program = argv[2];
	
	Program prog(program);

	if(command == "status") {
		prog.status(program);
		return 0;
	}

	if(command == "start") {
		prog.start(program);
		return 0;
	}

	if(command == "stop") {
		prog.stop(program);
		return 0;
	}

	if(command == "restart") {
		prog.stop(program);
		prog.start(program);
		return 0;
	}

	std::cerr << "unknown command" << std::endl;
	syntax(process);
	return 1;
}
