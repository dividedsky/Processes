// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
  int x = 42;

  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("child process pid: %d\n", (int) getpid());
    printf("x in the child is %d\n", x);
    x = 12;
    printf("x in child is now %d\n", x);
  } else {
    printf("parent process id: %d\nchild pid: %d\n", (int) getpid(), rc);
    printf("x in the parent is %d\n", x);
    x = 23;
    printf("x in the parent is now %d\n", x);
  }
  return 0;
}
