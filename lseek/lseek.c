#include <unistd.h>
#include <stdio.h>

int main(){
    if(lseek(STDIN_FILENO, 0 , SEEK_CUR) == -1){ //STDIN fd인 0, 
        printf("Error\n");
    }
    else{
        printf("seekOK\n");
    }
    return 0;
}