#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int count = 0;
int status = 0;

void sigcatch(int sig)
{
    printf("Process %d received signal %d\n", getpid(), sig);
	exit(0);
}

int main()
{   
    signal(SIGINT, sigcatch);
    int pid = fork();

    if(pid == 0){
        while(1);
    }
    else {
        printf("Child's pid is : %d\n", pid);
        kill(pid, 2);

        wait(&status);

        if(WIFEXITED(status)){
                printf("Child exited with code %d\n",                                  		       
                WEXITSTATUS(status));
        }
        else{
                printf("Child terminated abnormally\n");
        }

    }
}