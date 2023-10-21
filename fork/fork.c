#include <stdio.h>	/* fork1.c */
#include <unistd.h>
#include <stdio.h>

int main(void){
        int x;
        
        x = 0;
        int ret = fork();
        x = 1;
        printf("I am process %ld and my x is %d, fork ret : %d\n", (long)getpid(), x, ret);
        return 0;
}
