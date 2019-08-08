#include "types.h"
#include "stat.h"
#include "user.h"


void
threadtestthread(void)
{
  printf(1, "Hello from threadtestthread!!!\n");
}


void
threadtest(void)
{
  thread_t th;

  printf(1, "Start thread\n");
  if ((th = thread_create(threadtestthread)) < 0) {
    printf(1, "thread_create failed\n");
    return;
  }

  if (thread_join(th) < 0) {
    printf(1, "thread_join failed\n");
    return;
  }
  printf(1, "Thread joined\n");
}


int
main(void)
{
  threadtest();
  exit();
}
