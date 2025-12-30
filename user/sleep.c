#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc <= 1){
    exit(1);
  }

  int t = atoi(argv[1]);
  pause(t*10);

  exit(0);
}
