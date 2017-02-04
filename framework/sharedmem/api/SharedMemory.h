#ifndef SHAREDMEMORY_H
#define SHAREDMEMORY_H

#include <string>
#include <sys/types.h>

class SharedMemory {

public:
   SharedMemory(std::string file);
   ~SharedMemory();

   void attach();
   void detach();
   void update(std::string msg);
   std::string read();
   int size();

private:
   key_t segment;
   char* ptr;
};

#endif
