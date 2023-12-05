#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char s2[100];

    readlink("./hello",s2,100);
    printf("%s", s2);
    return 0;
}