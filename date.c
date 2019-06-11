#include "types.h"
#include "stat.h"
#include "user.h"
#include "date.h"

int main(int argc, char *argv[])
{
  struct rtcdate date;

  if (utctime(&date) < 0) {
    printf(1, "date: something went wrong\n");
    exit();
  }

  printf(1,
      "%d/%d/%d %d:%d:%d\n",
      (int)date.year, (int)date.month, (int)date.day,
      (int)date.hour, (int)date.minute, (int)date.second);

  exit();
}
