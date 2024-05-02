#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
 
//void error_handling(char *message);
 
int main(int argc, char *argv[]){
   int BUFSIZE = 0;
   int serv_sock;
   int str_len, num=0;
 
   struct sockaddr_in serv_addr;
   struct sockaddr_in clnt_addr;
   int clnt_addr_size;
 
   if(argc != 3){
       printf("Usage : %s <port> <buffersize>\n", argv[0]);
   exit(1);
   }
 
   serv_sock = socket(PF_INET, SOCK_DGRAM, 0);
   if(serv_sock == -1)
//      error_handling("UDP socket error");
       printf("UDP socket error");
 
   memset(&serv_addr, 0, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
   serv_addr.sin_port = htons(atoi(argv[1]));
 
   BUFSIZE = atoi(argv[2]);
   char message[BUFSIZE];
 
   if (bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1)
//      error_handling("bind() error");
       printf("bind() error");
  
   sleep(10); //충분한 시간동안 sleep한다음
 
   while(1) {
       clnt_addr_size = sizeof(clnt_addr);
       sleep(1);
       str_len = recvfrom (serv_sock, message, BUFSIZE, 0, //수신시작
           (struct sockaddr*)&clnt_addr, &clnt_addr_size);
       printf("Received message %d: ", num++);
       int i =0;
       while(i<BUFSIZE-1){
           if(message[i]!='#')
               printf("%c", message[i]);
           else
               break;
           i++;
        }
        printf("\n");
        sendto (serv_sock, message, str_len, 0, (struct sockaddr*)&clnt_addr, sizeof(clnt_addr));
	}
 
   return 0;
}