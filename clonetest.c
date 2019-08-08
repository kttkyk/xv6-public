#include "types.h"
#include "stat.h"
#include "user.h"

void
clonetest(void)
{
  int pid = 1;

  printf(1, "clone test\n");

  pid = clone();
  if (pid < 0) {
    printf(1, "cannot clone\n");
    return;
  }

  if (pid == 0)
    exit();

  printf(1, "child pid: %d\n", pid);

  if (wait() < 0) {
    printf(1, "wait failed\n");
    exit();
  }

  printf(1, "clone test OK\n");
}

int
main(void)
{
  clonetest();
  exit();
}
