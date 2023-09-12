#include <unistd.h>

int main(){
    if((write(1, "Welcome to System Programming", 29)) != 29){ // 바이트 수를 부족하게 입력할 경우 잘린다.
        write(2, "A Writer error has occurred on file descriptor 1 \n", 47);
        return -1;
    }

    return 0;
    // return 0과 exit(0)의 차이에 대해 알아볼 것
}