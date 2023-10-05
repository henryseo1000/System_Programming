#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    struct stat * s1 = (struct stat *)malloc(sizeof(struct stat));
    char s2[100];

    scanf("%s", s2);
    
    if(stat(s2, s1) == -1){
        printf("there is no such file named : %s\n", s2);
        return -1;
    }

    printf("l-node 번호 : %llu\n최초 생성 시간 : %s\n마지막으로 업데이트 된 시간 : %s\n마지막으로 접근한 시간 : %s\n", s1->st_ino, ctime(&(s1->st_ctime)), ctime(&(s1->st_mtime)), ctime(&(s1->st_atime)));
    return 0;
}