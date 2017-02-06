#include "Trace.h"
#include "Serial.h"
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

CLASS("Serial");

Serial::Serial(std::string file, Baud baud) {
   METHOD("Serial()");

   fd = open(file.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
   if(fd == -1) 
      EXCEPTION("UART Open error");

	struct termios options;
	tcgetattr(fd, &options);

	options.c_cflag = baud | CS8 | CLOCAL | CREAD;
	options.c_iflag = IGNPAR;
	options.c_oflag = 0;
	options.c_lflag = 0;
	tcflush(fd, TCIFLUSH);
	tcsetattr(fd, TCSANOW, &options);
}

Serial::~Serial() {
   METHOD("~Serial()");

   close(fd);
}

void Serial::tx(char* buf, int& length) {
   METHOD("tx(char[], int)");

   int count = write(fd, buf, length);
   if(count < 0)
      EXCEPTION("UART TX Error");

   length = count;
}

bool Serial::rx(char* buf, int& length) {
   METHOD("rx(char[], int)");

   bool count = read(fd, (void*)buf, length);
   if(count < 0) {
	EXCEPTION("UART Rx Error");
   } else if(count == 0) {
	length = 0;
	return false;
   } else {
	length = count;
	return true;
   }
}
