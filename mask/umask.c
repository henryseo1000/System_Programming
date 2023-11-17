#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mach/error.h>

int main(void) {
  umask(0); // umask가 0이면 not을 시킨 결과는 111 111 111이 될 것 -> 이 결과를 다시 protection bit와 OR 연산						
  if (creat("foo", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) < 0){} // "foo"라는 파일을 생성한다.	이때 유저, 그룹, 다른 사람에 대한 읽기 쓰기 권한만 열어놨으므로 권한은
       // 권한 : 000 110 110 110	
    //perror("foo");	// 만약 creat에 실패하면 에러 출력					    								

  umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH); // 이렇게 umask에 옵션을 주는 것도 가능한데, 그룹과 다른 사람들에 대한 읽기 쓰기 권한을 설정했으므로
   // umask는 000 000 110 110이 된다.
  if (creat("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                   S_IROTH | S_IWOTH) < 0){} // 이 상태에서 foo 파일과 같은 권한으로 bar 파일을 생성한다면 권한 비트는 어떻게 될까?
    //perror("bar");
  return 0;
}
