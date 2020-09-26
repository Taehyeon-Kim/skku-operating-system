//
//  main.cpp
//  Thread
//
//  Created by taehy.k on 2020/09/26.
//

// C++ 11 부터 표준에 thread가 추가되어서 thread사용이 매우 편리해졌다.

#include <iostream>
#include <stdio.h>
#include <thread>
using std::thread;

void func1() {
    for (int i = 0; i < 10; i++) {
        printf("쓰레드 1 작동중! \n");
    }
}

void func2() {
    for (int i = 0; i < 10; i++) {
        printf("쓰레드 2 작동중! \n");
    }
}

void func3() {
    for (int i = 0; i < 10; i++) {
        printf("쓰레드 3 작동중! \n");
    }
}

int main() {
    thread t1(func1);
    thread t2(func2);
    thread t3(func3);
    
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}
