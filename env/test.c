#include <stdlib.h> /* viewenv.c */
#include <stdio.h>
#include <unistd.h>

void end(int num);
int count = 0;

int main()
{
	signal(SIGINT, end);
	
	while(1){
		sleep(1);
		count++;
		printf("%d초\n", count);
	}
}

void end(int num){
	printf("%d초 경과\n", count);
	exit(0);
}