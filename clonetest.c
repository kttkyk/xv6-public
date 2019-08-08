#include "types.h"
#include "stat.h"
#include "user.h"

#define PGSIZE 0x1000

void
clonetestthread(void)
{
  printf(1, "Hello from clonetest!!\n");
}


void
clonetest(void)
{
  int pid;
  char *p;
  uint esp;

  p = malloc(PGSIZE * 2);
  if (p < 0) {
    printf(1, "malloc failed\n");
  }
  if ((uint)p % PGSIZE != 0) {
    p = (char *)((uint)(p) / PGSIZE);
  }
  esp = (uint)p + (PGSIZE * 2) - 0x4;
  *(uint *)esp = (uint)exit;

  printf(1, "clone test\n");

  pid = clone(clonetestthread, esp);
  if (pid < 0) {
    printf(1, "cannot clone\n");
    return;
  }

  if (wait() < 0) {
    printf(1, "wait failed\n");
    exit();
  }

  printf(1, "cloned child pid: %d\n", pid);
  printf(1, "clone test OK\n");
}

int
main(void)
{
  clonetest();
  exit();
}
