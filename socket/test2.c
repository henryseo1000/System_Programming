#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "socket"

int main() {
    int client_fd;
    struct sockaddr_un server_addr;

    // 클라이언트 소켓 생성
    if ((client_fd = socket(PF_UNIX, SOCK_DGRAM, 0)) == -1) {
        perror("client socket");
        exit(EXIT_FAILURE);
    }

    // 서버 주소 설정
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = PF_UNIX;
    strncpy(server_addr.sun_path, SOCKET_PATH, sizeof(server_addr.sun_path) - 1);

    printf("서버에 메시지를 전송하세요 (종료하려면 'exit' 입력):\n");

    // 표준 입력에서 입력을 읽어 서버로 전송
    char input[256];
    while (1) {
        fgets(input, sizeof(input), stdin);

        // "exit" 입력 시 종료
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        // 서버로 데이터 전송
        sendto(client_fd, input, strlen(input), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
    }

    // 소켓 닫기
    close(client_fd);

    printf("클라이언트 종료\n");

    return 0;
}