
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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


    printf("----- PREGUNTA PARA INVESTIGAR -----\n¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?\n\n");

}
void desafio6(){//.RUN_ME

}

void desafio7(){//filtrar error
    printf("Filter error\n");
    srand(time(NULL));

    char* hint= "La respuesta es K5n2UFfpFMUN\n";
    int largo = strlen(hint);
    int Min = 32, diff = 127-Min;
    for (int i = 0; i < largo; i++)
    {
        for (int j = 0; j < (((double)4/RAND_MAX) * rand() + 4); j++)
        {
            fprintf(stderr, "%c", (int) (((double)(diff+1)/RAND_MAX) * rand() + Min));
            fflush(stderr);
        }
        printf("%c", hint[i]);
        fflush(stdout);
    }
    
}

void desafio8(){

    printf("¿?\n\n");

    printf("\x1B[30;40m La respuesta es BUmyYq5XxXGt \x1B[0m\n");

    printf("----- PREGUNTA PARA INVESTIGAR -----\n¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?\n\n");
}


void desafio9(){//u^v

    printf("Latexme\n\nSi\n\\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\\frac{u'}{u})\nentonces\ny = \n\n");


    printf("----- PREGUNTA PARA INVESTIGAR -----\nsockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?\n\n");

}
void desafio10(){//quine

    int correcta=0;

    printf("quine\n\n");

    if(system("gcc quine.c -o quine") == 0) {
        printf("¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n\n");

        system("./quine > aux.txt");

        if(system("diff quine.c aux.txt") != 0){
            printf("diff encontró diferencias.\n\n");
        }else{
            correcta=1;
            printf("La respuesta es chin_chu_lan_cha\n\n");
        }

        system("rm -f aux.txt quine");
    }

    if(!correcta)
        printf("\nENTER para reintentar.\n\n");

    printf("----- PREGUNTA PARA INVESTIGAR -----\n¿Cuáles son las características del protocolo SCTP?\n\n");
}


void desafio11(){

}


void desafio12(){

}
