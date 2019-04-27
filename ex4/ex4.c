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
  if (child == 0) {
    char *args[] = {"/bin/ls", "ls"};
    execl(args[0], *args, NULL);
    printf("This line is nor run when calling exec\n");
  } else {
    char *args[] = {"/bin/ls", "ls", "/home"};
    char *pwd_args[] = {"/bin/pwd", "pwd"};
    /* execl(args[0], *args, NULL); */
    execl(args[0], *args, "../", NULL);
    execl("ex4", *args); // infite loop, program keeps calling itself
    /* execl(pwd_args[0], *pwd_args, NULL); */
    /* execl("/bin/pwd", "pwd", NULL); */
    printf("parent function\n");
  }
  /* char *args[] = {"/bin/ls", NULL}; */

    return 0;
}
