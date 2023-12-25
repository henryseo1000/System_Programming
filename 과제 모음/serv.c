#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define NAME "socket" 

int main() 
{ 
	int	sock, length, fromlen;
	struct sockaddr_un name, from;
	char buf[1024];
	fromlen = sizeof(from);
	
	sock = socket(PF_UNIX, SOCK_DGRAM, 0);

	name.sun_family=PF_UNIX;
	strcpy(name.sun_path, NAME); 

	if(bind(sock, &name, sizeof(struct sockaddr_un))){
        printf("bind error");
        return 1;
    }

	printf("socket --> %s\n", NAME);

	if(recvfrom(sock, buf, 1024, 0, (struct sockaddr *) &from, &fromlen) < 0){
        printf("recvfrom error\n");
        return 1;
    }
	printf("%s\n", buf); 

	unlink(NAME); 
	close(sock);
}
