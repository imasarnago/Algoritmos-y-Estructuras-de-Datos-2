#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n \n\n", sizeof (messi.name), sizeof(messi.age), sizeof(messi.height), sizeof(data_t));  
           /* El operador sizeof() devuelve la cantidad de 
              bytes ocupados por una expresión o tipo*/


                        // Primera forma de imprimir los valores de las direcciones de memoria:
    printf("La dirección de memoria de name es: %p \n \n", (void *)messi.name);
    printf("La dirección de memoria de name es: %p \n \n", (void *)&messi.age);
    printf("La dirección de memoria de name es: %p \n \n", (void *)&messi.height);


                        // Segunda forma de imprimir los valores de las direcciones de memoria:
    unsigned int  *q = NULL;
    unsigned int *s = NULL;
    q = &messi.age;
    s = &messi.height;
 
    printf("El indice de memoria alojado en p es : %lu \n", (uintptr_t)messi.name);
    printf("El indice de memoria alojado en p es : %lu \n", (uintptr_t)q);
    printf("El indice de memoria alojado en p es : %lu \n", (uintptr_t)s);


    /*   printf("El índice de memoria alojado en p es: %lu", (uintptr_t) p)  */
    return EXIT_SUCCESS;
}



/* ¿La suma de los miembros coincide con el total? ¿El tamaño del campo name depende del nombre que contiene?

Respuesta : La suma de los miembros no coincide con el tamaño toal que ocupa la estructura en memoria. 
Evidentemente el tamaño del campo name no depende del nombre que contiene. En este caso depende de 
el tamaño máximo que yo le haya fijado en la variable NAME_MAXSIZE (30). 


Analizar la salida de la impresión de las dos formas de direcciones de memoria y responder: 
¿Hay algo raro en las direcciones de memoria? 

Respuesta : 


*/

