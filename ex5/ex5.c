// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MSGSIZE 16

char* msg1 = "hello world #1\n";
char* msg2 = "hello world #2\n";
char* msg3 = "hello world #3\n";

int main(void)
{
  // Your code here
  int fd[2];

  pipe(fd);
  pid_t pid = fork();
  char buffer[MSGSIZE * 3];

  if (pid == 0) {
    write(fd[1], msg1, MSGSIZE);
    write(fd[1], msg2, MSGSIZE);
    write(fd[1], msg3, MSGSIZE);
  } else {
    int bytes_read = read(fd[0], buffer, sizeof(buffer));
    write(STDOUT_FILENO, buffer, bytes_read);
  }

  return 0;
}
