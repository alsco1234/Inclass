#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUFSIZE 1024
#define SCHEDULE 3

void error_handling(char *message);

int main(int argc, char **argv){
	int sock;
	int send_cnt = 0 ;
	
	struct sockaddr_in serv_addr;
	if(argc != 3){
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1)
		error_handling("socket() error");
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port=htons(atoi(argv[2]));
	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
		error_handling("connect() error!");
	while(send_cnt < SCHEDULE) {
		send_cnt += 1 ;
		char send_message[BUFSIZE] ;
		memset(send_message, 0, sizeof(char) * BUFSIZE) ;
		int str_len;
		fputs("Enter a message to send(# to end): ", stdout);
		while(1){
			char message[BUFSIZE];
			/* message input & send */
			fgets(message, BUFSIZE, stdin);
			if(!strcmp(message, "#\n"))
				break ;
			strcat(send_message, message) ;
		}
		int message_size = strlen(send_message) ;
		write(sock, &message_size, sizeof(int)) ;
		write(sock, send_message, message_size);
		/* print messages received */
		//str_len = read(sock, message, BUFSIZE-1);
		// message[str_len]= 0;
		//printf("A message from the server(%d) : %s \n", (int)strlen(message), message);
	}	
	close(sock);
	return 0;
}

void error_handling(char *message){
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
