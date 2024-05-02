#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 518
#define PAYLOAD_SIZE BUF_SIZE - 3 * sizeof(int)
#define SEQ_SIZE 16
#define FILE_NAME 1001
#define FILE_DATA 1002
#define FIN 1003
#define CONFIRM_FILE_NAME 2001
#define CONFIRM_FILE_DATA 2002
#define TRUE 1
#define FALSE 0

typedef struct _data{
    int header;
    int seq;
    int payload_size;
    char payload[PAYLOAD_SIZE];
}Data ;

typedef struct _acknowledge{
    int header;
    int seq;
}Acknowledge;

typedef char bool ;

int main(int argc, char* argv[]){
    int sock, i, SNS ;
    Data name_packet ;
    Data packet[SEQ_SIZE] ;
    bool debuggingToggle = FALSE ;
    Acknowledge* ack = (Acknowledge*)malloc(sizeof(Acknowledge));
    struct sockaddr_in serv_adr;

    if(argc != 6){
        // server의 IP address, server port number, GBN의 SWS (SWS <= 10), debugging message on/off, file name
    	printf("Usage : %s <IP> <port> <SWS> <debugging message toggle> <File Name>\n", argv[0]);
        exit(1);
    }
    if(10 < atoi(argv[3])){
        if(debuggingToggle)
            printf("ERROR...The window size entered exceeded 10.\n") ;
        exit(1) ;
    }


    if(debuggingToggle)
	printf("Socket setup\n") ;
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));
    SNS = atoi(argv[3]) ;
    debuggingToggle = (strcmp(argv[4], "on") == 0 || strcmp(argv[4], "ON") == 0) ;


    if(debuggingToggle)
	printf("Setup for receiver timeout\n") ;
    fd_set read, cp_fd;
    struct timeval timeout;
    FD_ZERO(&read);
    FD_SET(sock, &read);

    if(debuggingToggle)
	printf("FILE open: %s\n", argv[5]) ;
    FILE* fp;
    fp = fopen(argv[5], "rb");
    if(fp == NULL){
        printf("Can't open file.\n");
        exit(1);
    }

    if(debuggingToggle)
	printf("Build file name packet\n") ; 
    name_packet.header = FILE_NAME;
    strcpy(name_packet.payload, argv[5]);

    if(debuggingToggle)
	printf("Transfer file name\n") ;
    int ret_count = 0;
    while(1){
        if(debuggingToggle)
	    printf("Timeout setting\n") ;
        int result;
        cp_fd = read;
        timeout.tv_sec = 0;
        timeout.tv_usec = 500000;

        if(debuggingToggle)
	    printf("Retransmit 5 times. After than terminate program\n") ;
        if(ret_count < 5){
            sendto(sock, (Data*)&name_packet, sizeof(Data), 0, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
            ret_count++;
        }else{
            printf("The network is too congested.\n");
            exit(1);
        }

        if(debuggingToggle)
	    printf("Wait 0.5 seconds...\n") ;
        result = select(sock + 1, &cp_fd, 0, 0, &timeout);
        if(result > 0){
            int serv_adr_size = sizeof(serv_adr);
            recvfrom(sock, ack, sizeof(Acknowledge), 0, (struct sockaddr*)&serv_adr, &serv_adr_size);
            if(ack->header == CONFIRM_FILE_NAME){
                if(debuggingToggle)
	            printf("Well connected\n") ;
                break;
            }
        }
    }
    
    if(debuggingToggle)
        printf("Transfer file data\n") ;
    int seq = 0;
    int window = 0;
    int loop_flag = 1;
    int fin_flag = 0;
    int send_count = 0;
    while(loop_flag){
        if(debuggingToggle)
	    printf("Build file data packet as many as pipeline\n") ;    
        while(window < SNS){
            if((packet[seq].payload_size = fread(packet[seq].payload, 1, PAYLOAD_SIZE, fp)) > 0){
                packet[seq].header = FILE_DATA;
                packet[seq].seq = seq;
                seq = (seq + 1) % SEQ_SIZE;
            }else{
                packet[seq].header = FIN;
                packet[seq].seq = fin_flag ? 0 : seq;
                fin_flag = 1;
                seq = (seq + 1) % SEQ_SIZE;
            }
            window++;
            send_count++;
        }
        
        while(1){
            if(debuggingToggle)
	        printf("Timeout setting\n") ;
            int timer;
            cp_fd = read;
            timeout.tv_sec = 0;
            timeout.tv_usec = 100000;

            for(i = send_count; i > 0; i--){
                int temp_seq = (seq - i < 0) ? seq - i + SEQ_SIZE : seq - i;
                sendto(sock, (Data*)&packet[temp_seq], sizeof(Data), 0, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
                send_count--;
            }

            if(debuggingToggle)
	        printf("Wait 0.1 seconds...\n") ;
            timer = select(sock + 1, &cp_fd, 0, 0, &timeout);
            if(timer > 0){
                int serv_adr_size = sizeof(serv_adr);
                recvfrom(sock, ack, sizeof(Acknowledge), 0, (struct sockaddr*)&serv_adr, &serv_adr_size);
                int lower_bound = SEQ_SIZE + seq - SNS + 1;
                int upper_bound = SEQ_SIZE + seq;
                int ack_seq = (seq < SNS - 1 && ack->seq > seq)? ack->seq : SEQ_SIZE + ack->seq;
                if(ack->header == CONFIRM_FILE_DATA && ack_seq >= lower_bound && ack_seq <= upper_bound){
                    if(debuggingToggle)
	                printf("Well received\n") ;
                    window = window - (ack_seq - lower_bound + 1);
                    break;
                }else if(ack->header == FIN){
                    if(debuggingToggle)
	                printf("Ending condition\n") ;
                    loop_flag = 0;
                    break;
                }
            }else if(timer == 0){
                send_count = SNS;
            }
        }
    }

    fclose(fp);
    close(sock);
    return 0;
}
