#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int fd[2];
    char buffer[115200];
    if (pipe(fd) != 0){
        printf("pipe");
            exit(1);
    }
    else {
        for(int i = 0; i < 2; i++){
            printf("fd%d : %d", i, fd[i]);
        }
    }

    //dup2(fd[0], STDOUT_FILENO);

    int pid = fork();

    if (pid == 0){
        close(fd[1]);
        dup2(fd[0], 0);
        close(fd[0]);
        
        if(execlp("grep", "grep","telnet",(char *)0) == -1){
            printf("execlp child");
            exit(1);
        }

        printf("%s\n", buffer);
        printf("child done.");
        exit(0);
    }
    else {
        close(fd[0]);
        close(1);
        dup2(fd[1], 1);

        if(execlp("ps","ps","-ef",(char *)0) == -1){
            printf("execlp parent");
            exit(1);
        }
\
        wait(&pid);
        exit(0);
    }
    
}   