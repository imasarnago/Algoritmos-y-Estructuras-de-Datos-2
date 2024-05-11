#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if (x>=0) {
        *y = x;
    }else {*y=x;}
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---


    int *p = NULL;
    p = &res;
    absolute(a,p);

    printf ("El valor de res es : %d \n",res);

    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

/* El parametro 'int *y' es de tipo out, en este caos. Porque sólo escribe en la dirección de memoria apuntada por el puntero de nombre y. 
Creo que C tiene parámetros de tipo in e in/out. No tenemos variables que sean sólo de tipo out (que serian de sólo escritura). 
EL primer tipo lo vimos en el caso de "int *y"; luego el tipo in/out sería una variable de escritura y lectura al mismo tiempo. Un ejemplo: 
cuando creamos una variable temporal i para recorrer arreglos. Debemos leerla para saber si ya no se cumplen la o las
condiciones del bucle, pero también la escribimos al sumarle 1 en cada iteración del mismo.
*/