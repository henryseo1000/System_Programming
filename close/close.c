#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    int fd;
    char fname[] = "afile";

    if((fd = open(fname, O_RDWR)) == - 1){
        printf("error opening file");
    }

    close(fd);
    return 0;
}