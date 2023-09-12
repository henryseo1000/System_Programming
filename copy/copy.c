#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 512
#define PERMS 0644

/*
man ls
ls -l testfile
*/

int main(int argc, char **argv){
    char buffer[BUFSIZE];
    char * name = argv[0];
    char* filename1 = argv[1];
    char* filename2 = argv[2];
    int fd1, fd2;
    ssize_t nread;
    long total = 0;

    if ((fd1 = open(filename1, O_RDONLY)) == -1) {
        printf("error1");
        exit(1);
    }

    if ((fd2 = open(filename2, O_RDWR|O_CREAT, PERMS)) == -1){
        printf("error2");
        exit(1);
    }

    printf("fd : %d\n", fd2);

    while ((nread = read(fd1, buffer, BUFSIZE)) > 0){
        buffer[nread] = '\0';
        write(fd2, buffer, strlen(buffer));
        total += nread;
    }

    close(fd1);
    close(fd2);

    printf("%ld bytes read\n", total);
    printf("%s,%d\n", name, argc);
    exit(0);
}