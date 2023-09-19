#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <err.h>
#include <stdio.h>

char outbuf[50] = "";
int len = 0;
int nread = 0;

int main(){
    int fd;
    
    fd = open("test.txt", O_RDWR);

    len = lseek(fd, 0, SEEK_END) - lseek(fd, 10, SEEK_SET);
    nread = read(fd, outbuf, len);
    outbuf[nread] = '\0';

    printf("%s\n", outbuf);

    len = lseek(fd, -5, SEEK_END) - lseek(fd, 0, SEEK_SET);
    lseek(fd, 0, SEEK_SET);
    nread = read(fd, outbuf, len);
    outbuf[nread] = '\0';

    printf("%s\n", outbuf);

    return 0;
}