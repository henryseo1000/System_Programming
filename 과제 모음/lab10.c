#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int pid1 = fork();
    int pid2 = 0;
    int status1 = 0;
    int status2 = 0;

    if (pid1 == 0){
        execl("/bin/echo", "echo", "This is Child 1",(char*)0);
        exit(0);
    }
    else{
        pid2 = fork();
        if(pid2 == 0){
            execl("/bin/echo", "echo", "This is Child 2",(char*)0);
            exit(0);
        }
    }
    printf("Parent: Waiting for children\n");

    int pid3 = wait(&status1);
    int pid4 = wait(&status2);

    if(pid2 == pid3){
        printf("Parent: Second Child : %d\n", status1);
    }
    else if (pid1 == pid3){
        printf("Parent: First Child : %d\n", status1);
    }
    else {
        printf("Parent: Error : %d\n", status1);
    }

    if(pid2 == pid4){
        printf("Parent: Second Child : %d\n", status1);
    }
    else if (pid1 == pid4){
        printf("Parent: First Child : %d\n", status1);
    }
    else {
        printf("Parent: Error : %d\n", status1);
    }

    printf("Parent: All Children terminated\n");
}