#ifndef PID_H
#define PID_H

#include <string>

class Pid {

public:
   Pid(std::string dir);
   ~Pid();

   void save(std::string program, int pid);
   int  load(std::string program);

private:
   std::string directory;
};

#endif
