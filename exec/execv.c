#include <unistd.h>

int main(int argc, char* argv[]){

    char * av[3];

    av[0] = "ls";
    av[1] = argv[1];
    av[2] = (char*) 0;

    execv("/bin/ls", av); //처음 인자 값을 넘겨주느냐 아니냐에 따라 다른 결과가 나온다.(argv[1])
}