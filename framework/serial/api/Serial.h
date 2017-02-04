#ifndef SERIAL_H
#define SERIAL_H

#include <string>
#include "Baud.h"

class Serial {

public:
   Serial(std::string file, Baud baud);
   ~Serial();

   void tx(char* buf, int& length);
   bool rx(char* buf, int& length);

private:
   int fd;

};

#endif
