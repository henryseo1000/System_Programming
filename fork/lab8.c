#include <stdio.h>	/* fork1.c */
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define PERMS 0666

int main(){
    char buf[1024];
    pid_t buf2[1024];
    pid_t cur_pid;
    int read_bytes;
    int length = 0;
    int num = 0;
    int status = 0;

    int fd = open("./sample.txt", O_RDONLY);
    int fd2 = open("./output.txt", O_RDWR|O_CREAT, PERMS);

    while((read_bytes = read(fd, buf, 1024)) > 0){
        length += read_bytes;
    }

    printf("total bytes read : %d\n", length);

    for(num = 0; num < length; num++){
        if((cur_pid = fork()) == 0){
            //sleep(length - num);
            //lseek(fd2, 0, SEEK_END);
            write(fd2, buf, strlen(buf));
            write(fd2, "\n", 2);
        }
        else{
            buf2[num] = cur_pid;
            break;
        }
    }

    if(cur_pid){
        for(num = 0; num < length; num++){
            waitpid(buf2[num], &status, 0);
        }
    }
    
    return 0;
}