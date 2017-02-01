#include "Alsa.h"
#include "Trace.h"
#include <iostream>
#include <stdexcept>

CLASS("");

void vec(std::vector<std::string> vector) {
	for(std::string str : vector) {
		std::cout << "- " << str << std::endl;
	}
}

int main() {
	METHOD("main()");
	try {
		std::cout << "Version: " << Alsa::getVersion() << std::endl;
		std::cout << "Stream: " << std::endl; vec(Alsa::getStreamTypes());
		std::cout << "Access: " << std::endl; vec(Alsa::getAccessTypes());
		std::cout << "Formats: " << std::endl; vec(Alsa::getFormats());
		std::cout << "Subformats: " << std::endl; vec(Alsa::getSubFormats());
		std::cout << "States: " << std::endl; vec(Alsa::getStates());

		Alsa* alsa = new Alsa("default", SND_PCM_STREAM_PLAYBACK);
		alsa->setHardwareParameters(SND_PCM_ACCESS_RW_INTERLEAVED, SND_PCM_FORMAT_S16_LE, 2, 44100);
		alsa->prepare();
		short buf[] = {1,2,3};
		alsa->write(buf, 3);
		std::cout << "Handler: " << alsa->getHandlerName() << std::endl; 
		std::cout << "State: " << alsa->getStateName() << std::endl; 

		std::cout << "Pause: " << alsa->canSyncStart() << std::endl; 
		std::cout << "Pause: " << alsa->canPause() << std::endl; 
		std::cout << "Resume: " << alsa->canResume() << std::endl; 
		std::cout << "Access: " << alsa->getAccessName() << std::endl; 
		delete alsa;

		Alsa* alsa2 = new Alsa("default", SND_PCM_STREAM_CAPTURE);
		alsa2->setHardwareParameters(SND_PCM_ACCESS_RW_INTERLEAVED, SND_PCM_FORMAT_S16_LE, 2, 44100);
		alsa2->prepare();
		alsa2->read(buf, 3);
		delete alsa2;
		
	}
	catch(std::logic_error error) {
		std::cerr << "Exception: " << error.what() << std::endl;
	}
	return 0;
}

