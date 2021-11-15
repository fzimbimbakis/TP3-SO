#define PORT 8080
#define CONNECTIONS 5

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <string.h>
#include <desafios.h>

char* easter_egg=" _______________________\n"
                "< ESTO ES UN EASTER_EGG >\n"
                " -----------------------\n"
                "        \\   ^__^\n"
                "         \\  (oo)\\_______\n"
                "            (__)\\       )\\/\\\n"
                "                ||----w |\n"
                "                ||     ||";


typedef void (*funcs)();

funcs desafios[12]={(funcs)&desafio1,(funcs)&desafio2,(funcs)&desafio3,
                    (funcs)&desafio4,(funcs) &desafio5, (funcs)&desafio6, (funcs)&desafio7,
                    (funcs)&desafio8,(funcs) &desafio9, (funcs)&desafio10, (funcs)&desafio11, (funcs)&desafio12};


char* respuestas[12]={"entendido\n", "itba\n", "M4GFKZ289aku\n", "fk3wfLCm3QvS\n",
                     "too_easy\n", ".RUN_ME\n","K5n2UFfpFMUN\n","BUmyYq5XxXGt\n" , "u^v\n", "chin_chu_lan_cha\n",
                     "gdb_rules\n", "normal\n"};


void clientComunication(int fd){
    char buffer[1024] = {0};


    for(int i=0; i < 12; i++){

        int incorrect;
        int r;

        do{
            system("clear -x");

            incorrect=1;

            printf("------------- DESAFIO -------------\n");

            desafios[i]();

            if((r=read(fd, buffer, 1024)) <= 0) {
                close(fd);
                return;
            }

            if(strcmp(respuestas[i],buffer)==0)
                incorrect=0;
            else{
                printf("Respuesta incorrecta: %s\n", buffer);
                sleep(3);
            }

            bzero(buffer,r);


        }while(incorrect);
    }
    system("clear -x");

    printf("Felicitaciones, finalizaron el juego.\n\n");

}



int main(){
    int serverfd ,opt, new_fd;
    struct sockaddr_in address;
    int addrlen=sizeof (address);


    serverfd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if(serverfd < 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(serverfd, SOL_SOCKET,SO_REUSEPORT,&opt, sizeof(opt)) < 0){
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //"0.0.0.0"
    address.sin_port = htons( PORT );

    if(bind(serverfd, (struct sockaddr *)&address,sizeof(address)) < 0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if(listen(serverfd, CONNECTIONS) < 0){
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    new_fd=accept(serverfd, (struct sockaddr *)&address,(socklen_t*)&addrlen);
    if( new_fd < 0){
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    clientComunication(new_fd);

    close(serverfd);

    return 0;
}