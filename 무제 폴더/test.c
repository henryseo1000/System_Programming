#include <stdio.h>
#include <string.h>
#include <sys/types.h> /* utime.c */
#include <sys/stat.h>
#include <fcntl.h>
#include <utime.h>
#include <dirent.h>

int main(int argc, char** argv){
    DIR * dir_ptr = NULL;
    struct dirent *file = NULL;
    char * dir = argv[1];
    char * suffix = argv[2];

    dir_ptr = opendir(".");

    while(file = readdir(dir_ptr)){
        printf("%s, %ld\n ", file->d_name, file->d_ino);
    }

    closedir(dir_ptr);
    
    return 0;
}