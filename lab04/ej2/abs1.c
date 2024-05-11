#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x>=0) {
        y = x;
    }else {y=x;}

}

int main(void) {
    int a=0, res=0;

    absolute (a,res);
    printf ("El resultado es : %d",res);


    return EXIT_SUCCESS;
}


/* El valor que se muestra por pantalla es correcto, pero sólo en este caso. Si yo modificara el valor de a, la función main seguiría 
imprimiendo 0 por consola. Eso es porque la variable res sólo es asignada dentro del scope de la función 'absolute'. Al salir de ella, 
he perdido el valor modificado de res. Para solucionarlo, necesitaré punteros (ver abs2.c)*/
