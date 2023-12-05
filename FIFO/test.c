#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE 1024

int main()
{
    int nread = 0;
    int fd1, fd2, fd3, fd4;
	int res1 = mkfifo("./myfifo1", 0777);
    int res2 = mkfifo("./myfifo2", 0777);

    char buf[20];

    int pid = fork();

    if(pid == 0){
        fd1 = open("./myfifo1",O_WRONLY);
        fd2 = open("./myfifo2",O_RDONLY);
        write(fd1, "XYZ", 3);
        read(fd2, buf, 20);
        printf("%s\n", buf);
    }
    else {
        fd3 = open("./myfifo1",O_RDONLY);
        fd4 = open("./myfifo2",O_WRONLY);
        write(fd4, "ABC", 3);
        read(fd3, buf, 20);
        printf("%s\n", buf);
    }
    
}