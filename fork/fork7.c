#include  <sys/types.h>
#include  <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int    glob = 6;    /* external variable in initialized data */

int main(void) {
  int    var;    /* automatic variable on the stack */
  pid_t  pid;

  var = 88;
  printf("before fork\n");  
    //pid = fork();

  if ((pid = vfork()) < 0)
    perror("fork error");  
  else if (pid == 0) {    /* child */
    glob++;        
    var++;
    _exit(0);  /* child terminates */
  }

  /* parent */
  printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
  exit(0);
}
