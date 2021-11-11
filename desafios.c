
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "desafios.h"



void desafio1(){

    printf("Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\nEn este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\nAdemás tendrán que investigar otras preguntas para responder durante la defensa.\nEl desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta.\nAdemás, deberán implementar otro programa para comunicarse conmigo.\n\nDeberán estar atentos a los easter eggs.\n\n");

    printf("Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra \'entendido\\n\'\n\n\n");


    printf("----- PREGUNTA PARA INVESTIGAR -----\n¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?\n\n");

};


void desafio2(){

    printf("The Wire S1E5\n5295 888 6288\n\n\n");


    printf("----- PREGUNTA PARA INVESTIGAR -----\n¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n\n");

}


void desafio3(){

    printf("https://ibb.co/tc0Hb6w\n\n\n");

    printf("----- PREGUNTA PARA INVESTIGAR -----\n¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n\n");

}


void desafio4(){

    printf("EBADF...\n\n");
    //bad file descriptor

    if(write(13,"................................La respuesta es fk3wfLCm3QvS\n", strlen("................................La respuesta es fk3wfLCm3QvS\n"))<0)
        printf("write: Bad file descriptor\n");

    printf("\n----- PREGUNTA PARA INVESTIGAR -----\n¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?\n\n");

}
void desafio5(){


    printf("respuesta = strings:28\n\n\n");


    printf("----- PREGUNTA PARA INVESTIGAR -----\n¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?");

}
void desafio6(){

}
void desafio7(){

}
void desafio8(){

}
void desafio9(){

}
void desafio10(){

}
void desafio11(){

}
void desafio12(){

}