#include "Trace.h"
#include "Program.h"
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <iostream>

CLASS("Program");

Program::Program(std::string name) : Pid("."), Config("config.json") {
   METHOD("Program(std::string)");

}

Program::~Program() {
   METHOD("~Program()");

}

char** transform(std::vector<std::string> vector) {
   char ** array = new char*[vector.size()+1];
   for(size_t i = 0; i < vector.size(); i++){
      array[i] = new char[vector[i].size() + 1];
      strcpy(array[i], vector[i].c_str());
   }
   array[vector.size()] = (char*)NULL;
   return array;
}

void Program::exec(std::vector<std::string> environment, std::string program, std::vector<std::string> arguments) {
   METHOD("exec()");

   char** args = transform(arguments);
   char** envir = transform(environment);

   pid_t pid = fork();
   if(pid == 0) {
       INFO("Child");
       int res = execvpe(program.c_str(), args, envir);
       INFO("res " + res);
   } else {
       INFO("Parent");
       this->save(program, pid);
       signal(SIGCHLD, SIG_IGN);
       exit(0);
   }
}

bool isRunning(int pid) {
   return kill(pid, 0) == 0;
}

void Program::start(std::string process) {
   METHOD("start()");

   int pid = this->load(process);
   if(pid != -1) {
      if(isRunning(pid)) {
         std::cerr << "Already running" << std::endl;
         return;
      } else {
         std::cerr << "Should be running - restarting" << std::endl;
     }
   } 

   std::cout << "Starting " << process << std::endl;
   std::vector<std::string> envir;
   envir.push_back("test=1");

   std::vector<std::string> args;
   args.push_back("sleep");
   args.push_back("60");

   exec(envir, "sleep", args);
}

void Program::stop(std::string program) {
   METHOD("stop(std::string)");

   int pid = this->load(program);
   if(pid == -1) {
       std::cerr << "Not started" << std::endl;
       return;
   }

   if(isRunning(pid)) {
      kill(pid, SIGTERM);
   } else {
       std::cerr << "Not running" << std::endl;
   }
}

void Program::status(std::string program) {
   METHOD("status(std::string)");

   int pid = this->load(program);
   bool running = isRunning(pid);

   if(pid == -1) {
      std::cout << "Not running" << std::endl;
   } else {
      std::cout << "pid: " << pid << " (" << running << ")" << std::endl;
   }
}

