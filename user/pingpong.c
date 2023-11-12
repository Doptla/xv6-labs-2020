#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

// Use write to write Bytes,not fprintf!

int main(int argc, char *argv[])
{
  int p[2];
  pipe(p);
  if (fork() == 0)
  {
    if (read(p[0], 0, 1))
    {
      printf("%d: received ping\n", getpid());
      write(p[1], " ", 1);
      exit(0);
    }
  }
  else
  {
    write(p[1], " ", 1);
    wait((int *)0);
    // Result can predict,so discard
    if (read(p[0], 0, 1))
    {
      printf("%d: received pong\n", getpid());
      exit(0);
    }
  }

  exit(0);
}
