#include  <setjmp.h>  /* testjmp.c */
#include <stdio.h>
#include <stdlib.h>
//#include  "ourhdr.h"

static void  f1(int, int, int);
static void  f2(void);

static jmp_buf  jmpbuffer;

int main(void) {
       int  count;
       int  val;
       int  sum;
       int ret;

  count = 2; val = 3; sum = 4;
  printf("Initial values: count = %d, val = %d, sum = %d\n", count, val, sum);
  if ((ret = setjmp(jmpbuffer)) != 0) {
    printf("after longjmp: count = %d, val = %d, sum = %d\n", count, val, sum);
    printf("ret : %d\n", ret);
    exit(0);
  }
  printf("ret : %d\n", ret);
  count = 97; val = 98; sum = 99; /* changed after setjmp, before longjmp */
  f1(count, val, sum);    /* never returns */
}

static void f1(int i, int j, int k) {
  printf("in f1(): count = %d, val = %d, sum = %d\n", i, j, k);
  f2();
}

static void f2(void) {
  longjmp(jmpbuffer, 0);
}