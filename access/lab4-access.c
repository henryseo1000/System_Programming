#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    int fd = 0;
    char buf[20];
    int nread = 0;

    if (argc != 2)
        printf("usage: a.out <pathname>");

    if (access(argv[1], F_OK) < 0){
        fd = open(argv[1], O_CREAT | O_RDWR, 0644);
        write(fd, "hello world", 11);
        printf("filename %s created\n", argv[1]);
    }
    else{
        fd = open(argv[1], O_RDWR);
        nread = read(fd, buf, 20);
        buf[nread] = '\0';
        printf("filename confirmed, reading %d bytes...\n", nread);
        printf("%s\n", buf);
    }

    return 0;
}
