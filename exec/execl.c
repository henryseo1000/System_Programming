#include <unistd.h>

int main(int argc, char* argv[]){

    execl("/bin/ls", "ls", argv[1], (char*)0); //처음 인자 값을 넘겨주느냐 아니냐에 따라 다른 결과가 나온다.(argv[1])
}