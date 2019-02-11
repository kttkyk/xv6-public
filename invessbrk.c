#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"


int stdout = 1;


int
main(int argc, char *argv[])
{
    char *oldsz, *newsz;

    printf(stdout, "Test sbrk\n");

    oldsz = sbrk(1);
    printf(stdout, "Old size: %x\n", oldsz);

    newsz = sbrk(0);
    printf(stdout, "New size: %x\n", newsz);

    exit();
}
