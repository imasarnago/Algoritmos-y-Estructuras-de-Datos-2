#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

void set_name(name_t new_name, data_t *d) {
    /* COMPLETAR */
    /*  Yo quise hacer d->name = new_name, pero eso no funciona porque le estoy queriendo asignar 
        un valor a un arreglo y no a una posición del mismo. Lo que puedo hacer entonces es copiarle 
        a un string (que es un array de caracteres) otro string.*/    
    strncpy (d->name, new_name, NAME_MAXSIZE);

}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);
    name_t messi_full_name = "Lionel Messi";
    /* COMPLETAR */

    set_name (messi_full_name, &messi);

    print_data(messi);

    return EXIT_SUCCESS;
}

