#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

#define PORT 9000
#define IPADDR "127.0.0.1"
//enter로 server1에 연결만 해도 received data 출력됨
int main(){ //메인함수
  int c_socket; //client측 소켓 개방, int형
  struct sockaddr_in c_addr; //client 측 구조체 정의
  int n;

  char rcvBuffer[BUFSIZ]; //BUFSIZ까지 크기의 string을 받을 rcvBuffer 선

  c_socket = socket(PF_INET, SOCK_STREAM, 0);

  memset(&c_addr, 0, sizeof(c_addr));
  //c_addr 초기화 c_addr 에 0번부터 c_addr 사이즈 만큼 메모리 할당

  //client 구조체 내용 넣기(client의 요구사항)
  c_addr.sin_addr.s_addr = inet_addr(IPADDR); //요청할 주소

  //client측 -> ip주소 -> 32비트 ip주소 저장할 구조
  c_addr.sin_family = AF_INET; //client측 주소패밀리, ipv4 인터넷 프로토콜 사용
  c_addr.sin_port = htons(PORT); //client측 요구 9000번 포트 사용


  if(connect(c_socket, (struct sockaddr*) &c_addr, sizeof(c_addr)) == -1){
    printf("Can not connect\n"); //연결못함 print하고
    close(c_socket); //client socket 닫아라
    return -1;
    //return 값 -1은 connect 실패, 즉 false를 의미함
  }

  if((n=read(c_socket, rcvBuffer, sizeof(rcvBuffer)))<0){ //server 측 rcvBuffer가 없으면 실패
    return -1;
  }

  rcvBuffer[n] = '\0'; //null문자 삽입

  printf("received Data : %s\n", rcvBuffer );
  //rcvBuffer의 내용을 string으로 출력한다.

  close(c_socket); //출력이 끝나고 client 소켓 닫음
}
