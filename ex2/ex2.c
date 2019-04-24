// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  // declare pointer f and open the text file
  FILE *f;
  f = fopen("text.txt", "a+");

  /* just messing around with file reading */
  /* printf("%c\n", getc(f)); */
  /* char a = getc(f); */
  /* printf("a is %c", a); */
  /* while((fgetc(c, 1, f) != EOF)) { */
  /* /1* fgets(storage, 100, f); *1/ */
  /*   printf("%c", c); */
  /* } */

  int child = fork();
  if (child < 0) {
    printf("error forking\n");
  } else if (child == 0) {
    printf("I'm the child, pid %d\n", getpid());
    char *child_string = "I am the child!!\n";
    fwrite(child_string, 1, strlen(child_string), f);
  } else {
    printf("I'm the parent of child %d, pid %d\n", child, getpid());
    char *parent_str = "I am the parent!\n";
    fwrite(parent_str, 1, strlen(parent_str), f);
  }
    return 0;
}
