#include <stdio.h>
#include <string.h>
#include <sys/types.h> /* utime.c */
#include <sys/stat.h>
#include <fcntl.h>
#include <utime.h>
#include <dirent.h>


int match(char *s1, char *s2){  
    int diff = strlen(s1) - strlen(s2); 
    if (strlen(s1) > strlen(s2))  return(strcmp(&s1[diff], s2) == 0) ; 
    else  return(0); 
}

int main(int argc, char** argv){
    DIR * dir_ptr = NULL;
    struct dirent *file = NULL;
    char * dir = argv[1];
    char * suffix = argv[2];

    if((dir_ptr = opendir(dir)) == NULL) 
    {
        fprintf(stderr, "%s directory 정보를 읽을 수 없습니다.\n", dir);
        return -1;
    }

    while((file = readdir(dir_ptr)) != NULL) 
    {
        if(match(file->d_name, suffix)){
            printf("i-node : %lu\n", file ->d_ino);
            printf("filename : %s\n", file ->d_name);
            break;
        }

    }

    closedir(dir_ptr);
    
    return 0;
}