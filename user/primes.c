#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#define true 1

int Eratosthenes(int *p)
{
  int prime;

  int p1[2];
  pipe(p1);

  read(p[0], &prime, sizeof(prime));
  if (prime == 0)
    exit(0);
  printf("prime %d\n", prime);
  // printf("------------------");

  if (fork() == 0)
  {
    close(p[0]);
    close(p1[1]);
    Eratosthenes(p1);
  }
  else
  {
    while (true)
    {
      int num;
      int index = read(p[0], &num, sizeof(num));
      //printf("index : %d\n",index);
      if (index == 0)
      {
        break;
      }
      //printf("%d\n", num);
      if (num % prime)
      {
        //printf("%d\n", num);
        write(p1[1], &num, sizeof(num));
      }
    }
    //printf("a\n");
    close(p[0]);
    close(p1[1]);
    wait(0);
  }

  //printf("\n");
  exit(0);
}


int main(int argc, char *argv[])
{
  int p[2];
  pipe(p);
  for (int i = 2; i <=100; i++)
  {
    write(p[1], &i, sizeof(i));
  }

  // EOF
  close(p[1]);

  Eratosthenes(p);

  exit(0);
}
