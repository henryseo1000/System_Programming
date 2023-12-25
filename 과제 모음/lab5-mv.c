#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){

    if (argc != 3)
        printf("usage: a.out <oldname> <newname>");

    if(link(argv[1], argv[2]) == -1){
        printf("rename %s to %s: No such file or directory\n", argv[1], argv[2]);
        return -1;
    }
    unlink(argv[1]);

    return 0;
}
