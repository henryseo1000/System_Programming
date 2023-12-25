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

//printf("buf is : %s\n", buf);
    fd = open("./myfifo", O_WRONLY);
    while(1){
    memset(buf, 0x00, BUFSIZE);
nread = read(STDIN_FILENO, buf, BUFSIZE);

    nread = write(fd, buf, BUFSIZE);
    }
    close(fd);
}
