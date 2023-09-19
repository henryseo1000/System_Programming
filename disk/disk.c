#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFSIZE 1024
#define FILESIZE (100 * 1024 * 1024)
#define COUNT    FILESIZE / BUFFSIZE

int main() {
	int i, fd;
	char buf[BUFFSIZE];

	memset(buf, '.', BUFFSIZE);
	if ((fd=creat("file.write", S_IRUSR|S_IWUSR)) < 0)	
		exit(1);

	for (i=0; i < COUNT; ++i)
		write(fd, buf, BUFFSIZE);

	close(fd);

	exit(0);
}

// 시스템 호출을 불렀을 때 실제 제어가 OS에게 넘어거 커널로 넘어가는게 system cpu time
// 시스템 호출을 제외한 것이 User cpu time
// 버퍼 사이즈가 늘수록 실행 시간 감소
// 8kb부터 실행시간 안늘어남 -> 실행시간을 더욱 줄일 수 없다.(dram, hdd 사이 블록의 단위는 페이지, 페이지 하나가 8kb이기 때문임)
// 즉 32kb도 8kb 4개로 나눠서 처리하기 때문이다.