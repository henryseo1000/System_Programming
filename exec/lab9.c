#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int pid1 = fork();
    int pid2 = 0;
    int status = 0;

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

    printf("Parent: Watiting for children\n");
    wait(&status);
    wait(&status);
    printf("Parent: All Children terminated\n");

}

                                                                                
