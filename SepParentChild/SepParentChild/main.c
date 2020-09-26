//
//  main.c
//  SepParentChild
//
//  Created by taehy.k on 2020/09/26.
//

#include <stdio.h>
#include <unistd.h>

int main() {
    
    pid_t pid;
    
    int x = 0;
    
    pid = fork(); // fork함수는 부모 프로세스에게는 자식프로세스의 PID반환, 자식 프로세스에게는 0을 반환
    
    /*
     fork 이후에는 자식 프로세스가 부모 프로세스와 동일한 주소 공간의 복사본을 가지게 된다.
     하지만 코드가 pid값을 기준으로 분리되어 있기 때문에
     각 프로세스의 메모리 공간의 x값은 서로 달라지게 된다.
    */
    
    if(pid > 0) // 부모 코드
    {
        x = 1;
        printf("부모 PID : %ld, x : %d, pid : %d\n", (long)getpid(), x, pid);
    }
    else if(pid == 0) // 자식 코드
    {
        x = 2;
        printf("자식 PID : %ld, x : %d\n", (long)getpid(), x);
    }
    else // fork 실패
    {
        printf("fork fail.\n");
        return -1;
    }
    
    return 0;
    
}
