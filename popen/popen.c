#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>

int main()
{
	FILE *read_fp;
	char buffer[BUFSIZ +1];  // BUFSIZ는 256 또는 512 바이트
	int chars_read;

	memset(buffer, '\0', sizeof(buffer));
	read_fp = popen("uname -a", "r");
	if(read_fp != NULL) {
	         chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		if(chars_read > 0) {
			printf("output was:-\n%s\n", buffer);
		}
	pclose(read_fp);
	exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
