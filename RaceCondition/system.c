#include  <sys/types.h>  /* system.c */
#include  <sys/wait.h>
#include  <errno.h>
#include  <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int system(const char *cmdstring)  /* version without signal handling */
{
  pid_t pid;  int status;

  if (cmdstring == NULL)
    return(1);    /* always a command processor with Unix */

  if ( (pid = fork()) < 0) {
    status = -1;  /* probably out of processes */

  } else if (pid == 0) {        /* child */
    execl("/bin/sh", "sh", "-c", cmdstring, (char *) 0);
    _exit(127);    /* execl error */
  } else {              /* parent */
    while (waitpid(pid, &status, 0) < 0) // wait하지 않을 경우, 쉘이 하나 떠 있을 것.
      if (errno != EINTR) {
        status = -1; /* error other than EINTR from waitpid() */
        break;
      }
  }
  return(status);
}

int main(int argc, char** args){
    if (argc < 2){
        printf("인자가 너무 적습니다.\n");
        return -1;
    }
    system(args[1]);
    return 0;
}