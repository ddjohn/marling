#ifndef PROGRAM_H
#define PROGRAM_H

#include <Pid.h>

#include <string>
#include <vector>

class Program : Pid {

public:
   Program(std::string name);
   ~Program();

   void start(std::string program);
   void stop(std::string program);
   void status(std::string program);

   void exec(std::vector<std::string> environment, std::string program, std::vector<std::string> arguments);

private:

};

#endif
