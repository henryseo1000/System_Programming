#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE 1024

int main()
{
    int nread = 0;
    int fd = 0;
	int res = mkfifo("./myfifo", 0777);

    char buffer[BUFSIZE];


	if (res == 0) printf("FIFO created\n");

    fd = open("./myfifo", O_RDONLY);
	memset(buffer, 0, BUFSIZE);
    while(1){
	nread = read(fd, buffer, BUFSIZE);
	
	buffer[nread] = '\0';

	if(nread > 0){
		write(STDOUT_FILENO, buffer, BUFSIZE);
	}
    }
}
