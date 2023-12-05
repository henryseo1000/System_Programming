#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int isoriginal = 0;
    int pid[10];
    int status;


    for(int i = 0; i < 10; i++){
        if((pid[i] = fork()) == 0){
            exit(0);
        }
        else {
            //isoriginal = 1;
        }
    }

    for(int i = 9; i >= 0; i--){
        waitpid(pid[i], &status, 0);
        printf("process %d termed\n", pid[i]);
    }

    return 0;
}
