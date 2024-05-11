#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ARRAY_SIZE 7

static void
print_array(int a[], size_t length) {
    assert(length > 0);
    printf("[ %d", a[0]);
    for (size_t i=1; i<length; i++) {
        printf(", %d", a[i]);
    }
    printf("]\n");
}

int main(void) {
    int arr[ARRAY_SIZE] = {7, 4, 1, 3, 9, 3, 5};
    int *p=NULL;
    printf("before: ");
    print_array(arr, ARRAY_SIZE);
    /* ---------------------------- Reescribir ---------------------------- */
    //
    // Se pueden agregar cosas antes del `for` de ser necesario


    
    p = arr;        // Problem solved 
    //
    for (unsigned int i=0u; i < ARRAY_SIZE; i++) {
        p[i] = 0;      // Problem solved
    }
    /* -------------------------------------------------------------------- */
    printf("after : ");
    print_array(arr, ARRAY_SIZE);

    return EXIT_SUCCESS;
}


//  Se debe reescribir la sección de código indicada para que mediante el puntero p se
// inicialice en cero el arreglo arr sin utilizar los operadores & y * en ningún momento
