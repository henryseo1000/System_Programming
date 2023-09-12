#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define PERMS 0644

char * filename = "newfile.cpp";

int main(){
    int fd;
    if ((fd = open(filename, O_RDWR|O_CREAT, PERMS)) == -1){
        printf("error");
        exit(1);
    }

    exit(0);
}