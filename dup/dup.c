#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <mach/error.h>

int main()
{
  int  fd1;
  int  fd2;

  if((fd1 = creat("afile", S_IRUSR | S_IWUSR)) == -1)
    perror("afile");
  printf("This is displayed on the screen.\n");  
  close(STDOUT_FILENO);
  //dup(fd1);
  //close(fd1); 
  fd2 = creat("bfile", S_IRUSR | S_IWUSR);
  printf("This is written into the redirected file.\n");  
  printf("%d %d\n", fd1, fd2);  
  return 0;
}

// 2개의 file descriptor가 afile를 가리킨다.
// 표준 출력이 afile를 가리키므로 afile에 쓰임
// creat와 dup의 규칙을 한 번 찾아볼 것(실험 결과 : 비어있는 것 중 가장 낮은 fd 번호에 할당)
// dup2()는 복제를 당할 파일 디스크립터 번호를 따로 사용