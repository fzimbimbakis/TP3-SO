//https://www.geeksforgeeks.org/socket-programming-cc/

#define PORT 8080



#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char buffer[1024]={0};
int idx=0;


int main()
{
	struct sockaddr_in cliaddr;

	int socketfd=socket(PF_INET, SOCK_STREAM, 0);

    if(socketfd < 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

	cliaddr.sin_family = AF_INET;
    cliaddr.sin_port = htons(PORT);
    cliaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    if(connect(socketfd,(const struct sockaddr *) &cliaddr, sizeof(cliaddr))<0){
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while(1){
    	char c;
    	while((c=getchar())!='\n'){
            if(c==-1)
                break;
    		buffer[idx++]=c;
    	}
        if(c==-1) {
            send(socketfd,"", 0,0);
            break;
        }
    	buffer[(idx)++]='\n';
    	buffer[(idx)++]=0;
    	idx=0;
    	send(socketfd,buffer, strlen(buffer),0);
    	buffer[0] = 0;
    }

    close(socketfd);
	return 0;
}

