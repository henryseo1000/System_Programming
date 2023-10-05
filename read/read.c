#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFSIZE 512

/*
man ls
ls -l testfile
*/

int main(){
    char buffer[BUFSIZE];
    int fd;
    ssize_t nread;
    long total = 0;

    if ((fd = open("testfile",O_RDONLY)) == -1) {
        exit(1);
    }

    while ((nread = read(fd, buffer, BUFSIZE)) > 0){
        //printf("%ld bytes read\n", nread);
        total += nread;
    }

    close(fd);
    printf("%ld bytes read\n", total);
    exit(0);
}