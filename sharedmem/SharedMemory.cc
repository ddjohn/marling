#include "Trace.h"
#include "SharedMemory.h"
#include <string.h>

#include <sys/ipc.h>
#include <sys/shm.h>

CLASS("SharedMemory");

#define SHM_SIZE 1024

SharedMemory::SharedMemory(std::string file) {
   METHOD("SharedMemory(std::string)");

   if((segment = ftok(file.c_str(), 'R')) == -1)
      EXCEPTION(strerror(errno));

    INFO("sharedmem = 0x" << std::hex << segment);
}

SharedMemory::~SharedMemory() {
   METHOD("~SharedMemory()");

   shmctl(segment, IPC_RMID, 0); 
}

void SharedMemory::attach() {
   METHOD("attach()");

   int shmid;
   if((shmid = shmget(segment, SHM_SIZE, 0644|IPC_CREAT)) == -1)
      EXCEPTION(strerror(errno));
   
    if((ptr = (char*)shmat(shmid, NULL, 0)) == (void*)-1)
      EXCEPTION(strerror(errno));
}

void SharedMemory::detach() {
   METHOD("detach()");

   if(shmdt(ptr) == -1)
      EXCEPTION(strerror(errno));
}

void SharedMemory::update(std::string msg) {
   METHOD("update(std::string)");

   strncpy(ptr, msg.c_str(), SHM_SIZE);
}

int SharedMemory::size() {
   METHOD("size()");

  struct shmid_ds shmbuffer; 
  shmctl(segment, IPC_STAT, &shmbuffer); 
  return shmbuffer.shm_segsz; 
}
