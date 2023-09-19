#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <err.h>
#include <stdio.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(){
    int fd;

    if((fd = creat("file.hole", S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)) < 0){ //file.hole 파일 생성
        printf("createrr");
    }
    if(write(fd, buf1, 10)!=10){ // 해당 파일
        printf("buf1err");
    }
    if(lseek(fd, 40, SEEK_CUR)==-1){ //lseek는 커서 이동의 느낌이라고 생각하면 된다. 
        printf("lseekerr");
    }
    if(write(fd, buf2, 10)!=10){
        printf("buf2");
    }

    return 0;
}