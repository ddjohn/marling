#include "Trace.h"
#include "Pid.h"

#include <fstream>
#include <string.h>

CLASS("Pid");

Pid::Pid(std::string dir) {
   METHOD("Pid()");

   directory = dir;
}

Pid::~Pid() {
   METHOD("~Pid()");

}

void Pid::save(std::string program, int pid) {
   METHOD("save(std::string, int)");

   std::string filename = directory + "/" + program + ".pid";
   std::ofstream file(filename);

   if(file.is_open()) {
        file << pid;
        file.close();
   } else {

   }   
}

int Pid::load(std::string program) {
   METHOD("load(std::string)");

   std::string filename = directory + "/" + program + ".pid";
   std::ifstream file(filename);

   int pid;
   if(file.is_open()) {
       file >> pid;
       file.close();
       return pid;
   } else {
      return -1;
   }   
}

