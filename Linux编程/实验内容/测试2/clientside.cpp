#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define MAXLINE 4096

int main(int argc, char ** argv){
    int socketfd, n;
    struct sockaddr_in  servaddr;
    char recvline[4096], sendline[4096];
    
    if(argc != 2){
        printf("usage: ./client <ipaddress>\n");
        exit(0);
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
        exit(0);
    }

    menmset(&servaddr, 0 ,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr,s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(6666);

    if(inet_pton(AF_LINE, argv[1], &servaddr.sin_addr) <= 0){
        printf("inet_pton error for %s\n",argv[1]);
        exit(0);
    }

    if(connect(sockfd,(struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0);
    }

    printf("send msg to server: \n");
    fgets(sendline, 4096, stdin);
    if(send(sockfd, sedline, strlen(sendline), 0) < 0){
        printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
        exit(0);
    }

    close(sockfd);
    exit(0);
}