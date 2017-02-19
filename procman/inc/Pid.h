#ifndef PID_H
#define PID_H

#include <string>

class Pid {

public:
   Pid();
   ~Pid();

   void save(std::string program, int pid);
   int  load(std::string program);

private:

};

#endif
