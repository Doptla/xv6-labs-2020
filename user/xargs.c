#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"
int main(int argc, char *argv[]){
  int i, pid;
  char c, s[512];
  
  i = 0;

  while(read(0, &c, 1) != 0){
    if(c == 0) break;
    if(c == '\n'){
      s[i] = 0;
      //execute path
      pid = fork();
      if (pid == 0)
      {
        char *args[MAXARG];
        // put initial command
        for (int k = 0; k < argc; k++)
        {
          //printf("argv elem : %s\n",argv[k + 1]);
          int length = strlen(argv[k + 1]) + 1;
          //allocate memory
          args[k] = malloc(length);
          memcpy(args[k], argv[k + 1], length);
          //printf("param : %s\n", args[k]);
        }
        //extend command
        args[argc - 1] = s;
        //printf("main program : %s\n",args[0]);
        //printf("param : %s\n", args[1]);
        //printf("param : %s\n", argv[2]);
        //execute and replace child program
        exec(args[0], args);
      }
      wait(0);
      printf("\n");
      //init string
      i = 0;
      memset(s, 0, sizeof(s));
      continue;
    }
    //common
    s[i++] = c;
  }

  exit(0);
}