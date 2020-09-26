//
//  main.c
//  CreateProcess
//
//  Created by taehy.k on 2020/09/26.
//

#include <stdio.h>
#include <unistd.h> // fork 함수 이용하기 위함

int main() {
    
    // 메모리 생성
    int x = 0;
    
    // 프로세스 생성 (부모 - 자식)
    fork();
    
    // 부모 프로세스, 자식 프로세스 각각 코드 실행
    x = 1;
    printf("PID : %d, x : %d\n", getpid(), x);
    
    return 0;
}

