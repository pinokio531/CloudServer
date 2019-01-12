#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>

#define PORT 9000
//서버랑 연결되고 클라이언트가 끊기 전까지는 안끊기고 계속 통신
//inu incheon등 값을 입력 받고 답장을 해줌, client3
char buffer[BUFSIZ] = "hi, inu";
char abuffer[BUFSIZ] = "welcome, incheon";

int main(){
  int c_socket, s_socket;
  struct sockaddr_in s_addr, c_addr;
  int len;
  int n;
  int length;
  char rBuffer[BUFSIZ];
  char *temp;


  s_socket = socket(PF_INET, SOCK_STREAM, 0);

  memset(&s_addr, 0, sizeof(s_addr));
  s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  s_addr.sin_family = AF_INET;
  s_addr.sin_port = htons(PORT);

  if(bind(s_socket, (struct sockaddr*)&s_addr, sizeof(s_addr)) == -1){
    printf("Can not Bind \n");
    return -1;
  }

  if(listen(s_socket, 5) == -1){
    printf("listen Fail\n");
    return -1;
  }

  while(1){
    len = sizeof(c_addr);
    c_socket = accept(s_socket, (struct sockaddr*) &c_addr, &len);

    length = 0;
    temp = rBuffer;
    while((n = read(c_socket, temp, 1)) > 0){
      if(*temp == '\r') continue;
      if(*temp == '\n') break;
      if(*temp == '\0') break;

      if(length == BUFSIZ) break;
      temp++; length++;
    }

    rBuffer[length] = '\0';
    if(!strcmp(rBuffer, "inu")){
      n = strlen(buffer);
      write(c_socket, buffer, n);
    }

    if(!strcmp(rBuffer, "incheon")){
      n = strlen(abuffer);
      write(c_socket, abuffer, n);
    }

    close(c_socket);
  }

  close(s_socket);
}
