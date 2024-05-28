#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ansicolors.h"

#define MAX_LENGTH 1820


char *string_clone(const char *str, size_t length) {
    // char clon[MAX_LENGTH]; // Es una variable local que vive en el stack
    // char *output = clon;   // Apunta a una variable del stack
    // Lo arreglo màs abajo, haciendo que output apunte al heap, de manera que aquello a lo que apunta
    // no se pierda al morir la funcion.
    char *output = NULL;
    output = malloc(sizeof(char) * length  +1 );
    for (size_t i = 0; i < length; i++) {
        output[i] = str[i];
    }
    output[length] = '\0';
    return output;  // Ahora apunta a una direccion del heap
} 
// El error tiene que ver con el hecho de que la funcion devuelve un puntero a un 
// arreglo local (clon) que no podra ser accedido fuera de la misma porque vive en el stack. Modifico eso.

//  NOTA: Cuando se llama a string_clone, el parametro length es 1812, menor al MAX_LENGTH. Cuando aloco, le 
// doy length*sizeof(char)+1, porque al final quiero agregarle el caracter especial '\0'.



int main(void) {
    char *original=""
         "______ time ago in a galaxy far, far away...\n\n\n"
         ANSI_BRGOLD
         "         _______..___________.     ___      .______             \n"
         "        /       ||           |    /   \\     |   _  \\          \n"
         "       |   (----``---|  |----`   /  ^  \\    |  |_)  |          \n"
         "        \\   \\        |  |       /  /_\\  \\   |      /        \n"
         "    .----)   |       |  |      /  _____  \\  |  |\\  \\----.    \n"
         "    |_______/        |__|     /__/     \\__\\ | _| `._____|     \n"
         "                                                                \n"
         "____    __    ____      ___      .______           _______.     \n"
         "\\   \\  /  \\  /   /     /   \\     |   _  \\         /       |\n"
         " \\   \\/    \\/   /     /  ^  \\    |  |_)  |       |   (----` \n"
         "  \\            /     /  /_\\  \\   |      /         \\   \\    \n"
         "   \\    /\\    /     /  _____  \\  |  |\\  \\----..----)   |   \n"
         "    \\__/  \\__/     /__/     \\__\\ | _| `._____||_______/     \n"
         "\n\n\n"
         "                           Episode II \n\n"
         "                      ATTACK OF THE CLONES\n\n"
         "                There is  unrest in the Galactic\n"
         "                Senate. Several  thousand  solar\n"
         "                systems  have   declared   their\n"
         "                intentions to leave the Republic.\n\n"
         "                This      separatist     movement,\n"
         "                under  the   leadership   of  the\n"
         "                mysterious   Count   Dooku,   has\n"
         "                made it difficult for the limited\n"
         "                number   of   Jedi   Knights   to\n"
         "                maintain   peace   and  order  in\n"
         "                the galaxy.\n\n"
         "                Senator   Amidala,   the   former\n"
         "                Queen   of  Naboo,  is  returning\n"
         "                to  the  Galactic  Senate to vote\n"
         "                on the critical issue of creating\n"
         "                an    ARMY    OF   THE   REPUBLIC\n"
         "                to    assist    the   overwhelmed\n"
         "                Jedi....\n" ANSI_WHITE;
    char *copy=NULL;

    copy = string_clone(original, strlen(original) * sizeof(char));
    printf("Original:\n" ANSI_CYAN
            " %s\n", original);
    copy[0] = 'A';
    copy[1] = ' ';
    copy[2] = 'l';
    copy[3] = 'o';
    copy[4] = 'n';
    copy[5] = 'g';
    printf("Copia   :\n" ANSI_CYAN
           " %s\n", copy);

    free (copy);

    return EXIT_SUCCESS;
}

/* Esta implementacion tiene el inconveniente de que el puntero a char ocupa 8 bytes (tengo entendido 
que es algo que puede variar segùn la arquitectura del procesador de la maquina). Yo necesito ocupar 
mucho mâs que eso. Por lo tanto, multiplico la cantidad de caracteres que posee 'original' por
el tamaño de un byte. Ahora el programa se comporta de la manera esperada. */

