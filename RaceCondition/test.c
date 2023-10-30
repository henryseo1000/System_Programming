#include <sys/types.h>  /* tellwait1.c */
#include <mach/error.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void charatatime(char *);

int main(void) {
  pid_t  pid;

  if ( (pid = fork()) < 0) printf("fork error");
  else if (pid == 0)  charatatime("output from child\n");
  else                charatatime("output from parent\n");
  exit(0);
}

static void charatatime(char *str) {
  char  *ptr;
  int    c;

  setbuf(stdout, NULL);      /* set unbuffered */
  for (ptr = str; c = *ptr++; )
    putc(c, stdout);
}
