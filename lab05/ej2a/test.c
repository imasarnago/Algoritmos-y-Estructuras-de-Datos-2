#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#include "stack.h"




int main (void){
    stack s = stack_empty();
                                    // PROBEMOS EL PRIMER CASO PREGUNTADO EN LA CONSIGNA    (1)   OK
    s = stack_empty();
    s = stack_push(s, 4);
    printf("Stack con 1 elemento: \n");
    stack_print(s);
    printf("Hago stack_pop al stack con 1 elemento: \n");
    s = stack_pop(s);
    printf ("Pila luego de pop (quedara vacia) : \n)");
    stack_print(s);
                                    // PROBEMOS EL SEGUNDO CASO PREGUNTADO EN LA CONSIGNA   (2)   OK
    printf("Una vez vacia, puedo intentar insertarle elementos : \n");
    s = stack_push(s,22);
    //stack_print(s); // Si la pila es vacia, la implementacion me deja insertar elementos.
                                    
                                    // PROBEMOS EL TERCER CASO PREGUNTADO EN LA CONSIGNA    (3)   OK
    s = stack_push(s,21);
    s = stack_push(s,20);

    stack_print(s);


    s = stack_pop(s);
    s = stack_pop(s);
    s = stack_pop(s);


    stack_elem *array = stack_to_array(s);
    if (array != NULL) {
        unsigned int size = stack_size(s);
        for (unsigned int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        free(array);
    } else {
        printf("La pila está vacía y la funcion stack to array devuelve null en dicho caso! \n");
    }    



    return 0;
}