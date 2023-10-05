#include <sys/types.h>  /* unlink.c */
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <mach/error.h>
#include <stdio.h>

int main()
{
  int fd, len;
  char buf[20];

  fd = open("tempfile", O_RDWR | O_CREAT | O_TRUNC, 0666); //파일 생성
  if (fd == -1) perror("open1"); // 오류 발생하지 않음

  // tempfile을 연 상태에서 삭제할 경우 close 후에 unlink, 오류 발생은 안함
  unlink("tempfile");
  len = write(fd, "How are you?", 12);
  if (len != 12) perror("write");

  lseek(fd, 0L, SEEK_SET);
  
  len = read(fd, buf, sizeof(buf));
  if (len < 0) perror("read");
  buf[len] = '\0';
  printf("%s\n", buf);
  close(fd); //이때 tempfile은 삭제될 것이다.

    // 해당 파일을 열기 위해 시도할 경우 오류 발생
  fd = open("tempfile", O_RDWR);
  if (fd == -1) perror("open2");
  close(fd);
  return 0;
}