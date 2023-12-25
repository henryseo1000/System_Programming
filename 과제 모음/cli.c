#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define NAME "socket"

int main() 
{ 
	int	sock;
	struct sockaddr_un name;
	char buf[1024];
	
	sock = socket(PF_UNIX, SOCK_DGRAM, 0);
    if(sock == -1){
        printf("socket error!\n"); 
        close(sock);
        return 1;
    }
    else {
        printf("socket : %d\n", sock);
    }

    sprintf(buf, "This is a message from the client");

    memset(&name, 0, sizeof(name));
    name.sun_family = PF_UNIX;
	strncpy(name.sun_path, NAME, sizeof(name.sun_path)); 

	if(sendto(sock, buf, sizeof(buf), 0 , (struct sockaddr *)&name, sizeof(struct sockaddr_un)) < 0){
        printf("sendto error!\n"); 
        close(sock);
        return 1;
    }
    
    unlink(NAME); 
	close(sock);
}