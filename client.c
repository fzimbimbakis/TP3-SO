//https://www.geeksforgeeks.org/socket-programming-cc/

#define PORT 8080



#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

char buffer[1024]={0};
int idx=0;


int main()
{
	struct sockaddr_in cliaddr;

	int socketfd=socket(PF_INET, SOCK_STREAM, 0);

	cliaddr.sin_family = AF_INET;
    cliaddr.sin_port = htons(PORT);
    cliaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    connect(socketfd,(const struct sockaddr *) &cliaddr, sizeof(cliaddr));

    //que corte cuando mandamos EOF
    while(1){
    	char c;
    	while((c=getchar())!='\n'){
    		buffer[idx++]=c;
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

