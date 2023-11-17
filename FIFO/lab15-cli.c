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
    char buf[BUFSIZE];
    int fd = 0;
    int nread = 0;

	scanf("%s", buf);

    fd = open("./myfifo", O_CREAT | O_RDWR);

    write(fd, buf, BUFSIZE);

    close(fd);
}