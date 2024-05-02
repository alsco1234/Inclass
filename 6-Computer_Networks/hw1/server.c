#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFSIZE 512

struct packet{
    //header
    short s_port_num; //2 byte
    short d_port_num; //2 byte
    short total_num; //2 byte
    short checksum; //2 byte
    //data
    char data[512]; //512 byte
};

int main(int argc, char *argv[]){
    int serv_sock;
    int str_len, num=0;

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    int clnt_addr_size;

	// server의 argument : 자신의 port num, debugging message (on, off)
    if(argc != 3){
        printf("Usage : %s <port> <debugging>\n", argv[0]);
    	exit(1);
    }

	// server의 socket 만들기
    serv_sock = socket(PF_INET, SOCK_DGRAM, 0);
    if(serv_sock == -1 && !strcmp(argv[2], "on")) 
		printf("UDP socket error");
	
	// server address 정보 넣기
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

	// binding
    if (bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1)
        if(!strcmp(argv[2], "on")) printf("bind() error");

    /* 패킷 받기 */
    int packet_num = (108399/512); //총 패킷의 수
    struct packet * temp = malloc(sizeof(struct packet)); //패킷 선언
    struct packet this_pkt;
    char filename[512] = "";

    // 1. 첫 번째 패킷에서 파일 이름 받기
    str_len = recvfrom(serv_sock, temp, sizeof(*temp), 0, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    if(str_len < 0)
        printf("error");
    printf("recevied : 0 [%s]\n", temp->data);
    strcpy(filename , temp->data);

    // 2. 데이터 받아 파일에 쓰기
    FILE *f = fopen(filename, "w");
    int i= 0;
    int count=0;
    while(1){
        clnt_addr_size = sizeof(clnt_addr);
        str_len = recvfrom(serv_sock, temp, sizeof(*temp), 0, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
        count++;
        if(str_len < 0)
            printf("error");
        printf("recevied : %d [%s]\n", count, temp->data);
        fputs(temp->data, f);
        if(count==212)
            break;
    }
    fclose(f);
    return 0;
}

