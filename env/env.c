#include <stdlib.h> /* viewenv.c */
#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main()
{
	char **env = environ;
	
	//sleep(100);

	while(*env){
		printf("%s\n",*env);
		env++;
	}
	exit(0);
}
