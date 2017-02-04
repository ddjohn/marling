#include "Trace.h"
#include <iostream>
#include <stdexcept>
#include <zmq.hpp>
#include <unistd.h>

CLASS("");

int main() {
	METHOD("main()");

    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://*:5555");

    while (true) {
        zmq::message_t request;

        socket.recv (&request);
        std::cout << "Received Hello" << std::endl;

        sleep(1);

        zmq::message_t reply (5);
        memcpy (reply.data (), "World", 5);
        socket.send (reply);
    }

	try {
	}
	catch(std::logic_error error) {
		std::cerr << "Exception: " << error.what() << std::endl;
		return 1;
	}
	return 0;
}

