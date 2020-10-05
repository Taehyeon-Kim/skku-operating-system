//
//  main.cpp
//  MessagePassing
//
//  Created by Kim Tae Hyeon on 2020/10/04.
//  Ref. https://doitnow-man.tistory.com/119 [즐거운인생 (실패 또하나의 성공)]
//       https://www.geeksforgeeks.org/ipc-using-message-queues/
//  생산자 즉, 송신측 코드 구현

#include <iostream>
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>

struct msg_buffer
{
  long msg_type;      // 필수 요소 (메시지 타입을 기준으로 하여 받아들일 메시지를 지정하게 됨)
  char msg_text[256]; // 메시지 내용
};

int main(void)
{
  key_t key_id;                // key_id 변수 생성
  struct msg_buffer my_buffer; // 구조체를 이용한 변수 생성

  // 메시지 큐 할당 과정 (키 값을 가지고 메시지 큐를 만들게 됨)
  key_id = msgget((key_t)1234, IPC_CREAT | 0666);

  // 에러 처리
  if (key_id == -1)
  {
    perror("msgget error : ");
    return 0;
  }

  // 할당된 아이디 확인
  printf("Key is %d\n", key_id);

  // 메시지를 보내기 위한 과정
  memset(&my_buffer, 0, sizeof(msg_buffer)); // 메모리 할당
  my_buffer.msg_type = 1;                    //메시지 타입을 1로 지정
  printf("Send data is : ");
  fgets(my_buffer.msg_text, sizeof(my_buffer.msg_text), stdin); // 보낼 메시지 저장

  // 메시지 Send
  msgsnd(key_id, &my_buffer, sizeof(my_buffer), 0);

  // 보낸 메시지 확인
  printf("Sending data is done. The message is %s\n", my_buffer.msg_text);

  return 0;
}
