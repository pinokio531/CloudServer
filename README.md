# CloudServer
cloud server를 이용 통신

## Cloud Server

```
  - 서버 환경 : Linux Ubuntu
  
  - IP : 포트포워딩 설정 없이 공인 IP 할당받아 사용
  
  - PORT : 20, 21, 22 개방
  
```  
## 연결 방법 : Terminal(mac) or Putty(windows) 사용
  
  ```
  - $ ssh root@(Ip address)
  
  ```
    -> 포트포워딩을 사용할 경우 ip adress 뒤에 "-p (port)" 붙여줄것, ssh는 22번 포트를 사용
       ex) ssh root@(ip address) -p 8080
 ```      
  - node.js의 사용
  ```
    -> (https://nodejs.org/ko/download/package-manager) 참고하여 node 설치
  ```  
  - c언어 사용
  ```
    -> $ gcc -o (project) (project.c)
          - 위 명령어 실행시 project.c 를 컴파일한 project가 생성됨
          
    -> $ ./ (project)
          - 만들어진 project의 실행
  ```
```
