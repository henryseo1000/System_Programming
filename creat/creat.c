#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define PERMS 0644

char * filename = "newfile2.cpp";

int main(){
    int fd;
    if ((fd = creat(filename, PERMS)) == -1){
        printf("error");
        exit(1);
    }

    exit(0);
}