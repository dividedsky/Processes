// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here    
  int child = fork();
  char *args[] = {"/bin/ls", "ls"};
  if (child == 0) {
    execl(args[0], *args, NULL);
    printf("This line is nor run when calling exec\n");
  } else {
    printf("parent function\n");
  }
  /* char *args[] = {"/bin/ls", NULL}; */
  /* execvp(args[0], args); */

    return 0;
}
