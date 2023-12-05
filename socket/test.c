#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "socket"

int main() {
    int server_fd;
    struct sockaddr_un server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // 서버 소켓 생성
    if ((server_fd = socket(PF_UNIX, SOCK_DGRAM, 0)) == -1) {
        perror("server socket");
        exit(EXIT_FAILURE);
    }

    // 소켓 주소 설정
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = PF_UNIX;
    strncpy(server_addr.sun_path, SOCKET_PATH, sizeof(server_addr.sun_path) - 1);

    // 소켓 주소를 소켓에 바인딩
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    printf("서버가 연결 요청을 기다리고 있습니다...\n");

    // 클라이언트로부터 메시지 수신 및 출력
    char buffer[256];
    ssize_t bytes_received;

    while (1) {
        // 클라이언트로부터 데이터 수신
        bytes_received = recvfrom(server_fd, buffer, sizeof(buffer), 0,
                                  (struct sockaddr*)&client_addr, &client_len);
        if (bytes_received == -1) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        // 수신된 데이터 출력
        printf("수신된 메시지: %.*s", (int)bytes_received, buffer);
    }

    // 소켓 닫기
    close(server_fd);

    // 소켓 파일 제거
    unlink(SOCKET_PATH);

    printf("서버 종료\n");

    return 0;
}