#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int count = 0;

void sigcatch1()
{
	count ++;
    printf("pressed : %d\n", count);
}

void sigcatch2()
{
	exit(1);
}

int main()
{
    signal(SIGINT, sigcatch1);
    signal(SIGQUIT, sigcatch2);
	for( ; ; ) pause();
}