/*
fork()를 통해, 부모 - 자식 프로세스에서 시그널 들어오는 것을 확인해보는 예제
ref. https://www.geeksforgeeks.org/signals-c-language/?ref=lbp
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// signal(signum, handler)
// 시그널 함수는 기본적으로 2개의 파라미터를 요구한다.
// signum 와 handler

// handler함수는 single integer parameter를 요구하고
// return값은 void이다.
// 핸들러 함수
void handler(int signum)
{
  printf("The PID:%d process - SIGINT signal occured!, The sig# is %d\n", getpid(), signum);
}

int main()
{
  fork(); // 자식 프로세스 생성

  signal(SIGINT, handler); // 시그널을 보냄
  while (true)
  {
    printf("The PID:%d process is working.\n", getpid());
    sleep(1);
  }
  return 0;
}