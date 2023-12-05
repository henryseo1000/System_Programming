#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 512

/*
man ls
ls -l testfile
*/

int main(){
    char buffer[BUFSIZE];
    int fd1, fd2;
    ssize_t nread;
    long total = 0;

    if ((fd1 = open("testfile",O_RDWR)) == -1) {
        exit(1);
    }
    if ((fd2 = open("testfile2",O_RDWR)) == -1) {
        exit(1);
    }

    memset(buffer,0,BUFSIZE);

    while ((nread = read(fd1, buffer, BUFSIZE)) > 0){
        //printf("%ld bytes read\n", nread);
        total += nread;
        //buffer[nread] = '\0';
        write(fd2, buffer, nread);
    }

    close(fd1);
    close(fd2);
    printf("%ld bytes read\n", total);
    exit(0);
}