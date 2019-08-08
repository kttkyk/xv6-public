#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "x86.h"


#define PGSIZE 0x1000


// Clone process and start executing thread function in it with a new stack.
// Limitations: 
//  - No arguments for thread function
//  - Can not join per thread_t (Calling thread_join will wait for all the processes)
thread_t
thread_create(void (*thread)())
{
  thread_t th;
  uint esp;
  char *p;

  if ((p = malloc(PGSIZE * 2)) < 0)
    return -1;

  if ((uint)p % PGSIZE != 0)
    p = (char *)((uint)(p) / PGSIZE);

  esp = (uint)p + (PGSIZE * 2) - 0x4;
  // Set old eip.
  // Make function thread to return to exit.
  *(uint *)esp = (uint)exit;

  th = clone(thread, esp);
  return th;
}


// Make no user of th lol.
// TODO: Implement waitpid to specify which child to wait for.
// Limitation: Calling this will wait for all the cloned processes.
int
thread_join(thread_t th)
{
  if (wait() < 0) {
    return -1;
  }
  return 1;
}
