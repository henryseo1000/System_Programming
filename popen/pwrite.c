#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	FILE *write_fp;
	char buffer[BUFSIZ + 1];


    memset(buffer, '\0', BUFSIZ);
	sprintf(buffer, "Once upon a time, there was…\n");
    
	if(write_fp == NULL) {
		printf("null\n");
	}
    else {
        //fwrite(buffer, sizeof(char), strlen(buffer), write_fp);
		pclose(write_fp);
		exit(EXIT_SUCCESS);
    }

    write_fp = popen("od -c", "w");

	exit(EXIT_SUCCESS);
}
