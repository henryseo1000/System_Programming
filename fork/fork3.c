#include <stdio.h>	/* fork2.c */
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int x = 1;
    pid_t pid = fork();
    if (pid == 0) {
	printf("Child has x = %d\n", ++x); // pid가 0인 경우
    } else {
	printf("Parent has x = %d\n", --x); // pid가 0이 아닌 경우 = parent
    }
    printf("Bye from process %d with x = %d\n", getpid(), x);
}
