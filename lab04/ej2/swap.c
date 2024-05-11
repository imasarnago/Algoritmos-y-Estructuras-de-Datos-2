#include <stdlib.h>
#include <stdio.h>



void swap (int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b  = aux;
}



int main (void) {
    int x,y;
    int *p,*q;
    p = &x;
    q = &y;

    x = 6;
    y = 4;

    printf ("x : %d,  y : %d\n",x,y);


    swap (p,q);

    printf ("El valor de x es: %d, y el de y es: %d \n", *p,*q);
return 0;
}

