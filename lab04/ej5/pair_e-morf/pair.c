#include <stdio.h>
#include <stdlib.h>

#include "pair.h"

typedef struct s_pair_t {
    elem fst;
    elem snd;
} s_pair_t; 




pair_t pair_new(elem x, elem y) {
    pair_t new_pair = (pair_t)malloc(sizeof(s_pair_t));
    new_pair->fst = x;
    new_pair->snd= y;
    return new_pair;
    
}

int pair_first(pair_t p) {
    return p->fst;
}

int pair_second (pair_t p) {
    return p->snd;
}

pair_t pair_swapped(pair_t p) {
    pair_t np = pair_new(p->fst,p->snd);
    elem tmp = p->fst;
    np->fst = p->snd;
    np->snd = tmp;
    return np;
}

pair_t pair_destroy(pair_t p) {
    free(p);
    return NULL;    
}


/*estaría aún mas encapsulado si el usuario del codigo no tuviera ninguna forma de 
ver su implementación. En este caso, como se asume el rol de implementador y usuario al mismo tiempo,
es posible saber cómo se encuentra implementado el código, de algún modo "rompiendo la abstracción"

Tuve que definir el struct en pair.h y no en pair.c (afectando el encapsulamiento), porque sino en la funcion main me decia algo como 
"no se permite un puntero a un tipo "struct s_pair_t" incompleto.

*/