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

    fd = open("./myfifo", O_CREAT | O_RDWR);

	while ((nread = read(fd, buffer, BUFSIZE)) > 0){
        buffer[nread] = '\0';
        write(1, buffer, strlen(buffer));
    }

    close(fd);
}
